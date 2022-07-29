#include <bits/stdc++.h>
using namespace std;

vector <int> adj[101];
bool vis[101];
int lessthan[101];
int morethan[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        fill(vis + 1, vis + n + 1, 0);
        int cnt = 0;
        queue <int> q;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                vis[nxt] = true;
                q.push(nxt);
                cnt++;
                lessthan[nxt]++;
            }
        }
        morethan[i] = cnt;
    }
    int idx = n/2 + 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(morethan[i] >= idx) ans++;
        if(lessthan[i] >= idx) ans++;
    }
    cout<<ans;
}