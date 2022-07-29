#include <bits/stdc++.h>
using namespace std;

vector <int> adj[505];
int dist[505];
queue <int> q;
int cnt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int v,u;
        cin>>v>>u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    fill(dist + 1, dist + n + 1, -1);
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] < 3 && dist[i] > 0) cnt++;
    }
    cout<< cnt;
}