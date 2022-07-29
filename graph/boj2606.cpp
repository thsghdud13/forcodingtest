#include <bits/stdc++.h>
using namespace std;
vector <int> adj[103];
queue <int> q;
bool vis[103];
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = true;
            q.push(nxt);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        cnt++;
    }
    cout << n - cnt - 1;
}