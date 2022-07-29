#include <bits/stdc++.h>
using namespace std;

vector <int> adj[505];
bool vis[505];

void dfs(int cur){
    vis[cur] = true;
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int n , m, cnt = 0;
        cin>>n>>m;
        if(n == 0) break;
        cnt++;
        while(m--){
            int x ,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
    }
}