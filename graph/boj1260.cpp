#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
bool visdfs[1005];
bool visbfs[1005];
queue <int> q;
stack <int> s;
int n,m,v;

void dfs(int start){
    s.push(start);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(visdfs[cur]) continue;
        cout<<cur<<' ';
        visdfs[cur] = true;
        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][adj[cur].size() - 1 - i];
            if(visdfs[nxt]) continue;
            s.push(nxt);
        }
    }
}

void bfs(int start){
    q.push(start);
    visbfs[start] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<' ';
        for(auto nxt : adj[cur]){
            if(visbfs[nxt]) continue;
            visbfs[nxt] = true;
            q.push(nxt);
        }
    }

}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>> n >> m >> v;
    while(m--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs(v);
    cout<<'\n';
    bfs(v);
}
//생각보다 디테일 많이필요.