#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int d[255][255];
int nxt[255][255];
int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        fill(d[i] + 1, d[i] + n + 1, INF);
    while(m--){
        int u,v,b;
        cin>>u>>v>>b;//b가 0 이면 일방통행
        d[u][v] = 0;
        if(b) d[v][u] = 0;
        if(!b) d[v][u] = 1;
    }
    
    for(int i = 1; i <= n; i++)
        d[i][i] = 0;
    
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }

    cin>>k;
    while(k--){
        int s,e;
        cin>>s>>e;
        cout<<d[s][e]<<'\n';
    }
}