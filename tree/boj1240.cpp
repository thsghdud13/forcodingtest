#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> adj[1005];
int dist[1005][1005];
int p[1005];
int nd[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n-1; i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back(y);
        adj[y].push_back(x);
        dist[x][y] = z;
        dist[y][x] = z;
    }
    while(m--){
        int x,y;
        cin>>x>>y;
        fill(p,p + 1005, 0);
        fill(nd,nd + 1005, 0);
        queue <int> q;
        q.push(x);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(p[cur] == nxt) continue;
                nd[nxt] = dist[cur][nxt] + nd[cur];
                q.push(nxt);
                p[nxt] = cur;
            }
        }
        cout<<nd[y]<<'\n';
    }
}