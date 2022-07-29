#include <bits/stdc++.h>
using namespace std;

vector <int> adj[32005];
int deg[32005];
int n, m;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        deg[y]++;
    }
    queue <int> q;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<' ';
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
}