#include <bits/stdc++.h>
using namespace std;

int v,e;
int d[405][405];
int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;

    for(int i = 1; i <= v; i++)
        fill(d[i] + 1, d[i] + v + 1, INF);
    while(e--){
        int a,b,cost;
        cin>>a>>b>>cost;
        d[a][b] = cost;
    }
    for(int i = 1; i <= v; i++)
        d[i][i] = 0;

    for(int k = 1; k <= v; k++)
        for(int i = 1; i <= v; i++)
            for(int j = 1; j <= v; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int mn = INF;
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(d[i][j] == INF || d[j][i] == INF || d[i][j] == 0) continue;
            mn = min(mn, d[i][j] + d[j][i]);
        }
    }
    if(mn == INF) cout<< -1;
    else cout<<mn;
}