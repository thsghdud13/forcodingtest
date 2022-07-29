#include <bits/stdc++.h>
using namespace std;

int INF = 0x3f3f3f3f;
int n,m,r;
int item[105];
int howManyItem[105];
int d[105][105];
int nxt[105][105];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>r;
    for(int i = 1; i <= n; i++){
        cin>>item[i];
    }
    for(int i = 1; i <= n; i++)
        fill(d[i]+1,d[i] + 1 + n,INF);

    while(r--){
        int a, b, cost;
        cin>>a>>b>>cost;
        d[a][b] = cost;
        d[b][a] = cost;
    }

    for(int i = 1; i <= n; i++)
        d[i][i] = 0;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    nxt[i][j] = nxt[i][k];
                }
            }


    for(int i = 1; i <= n; i++){
        int total = item[i];
        for(int j = 1; j <= n; j++){
            if(d[i][j] > m || d[i][j] == 0 || d[i][j] == INF) continue;
            total += item[j];
        }
        howManyItem[i] = total;
    }
    cout<<*max_element(howManyItem + 1, howManyItem + n + 1);
}