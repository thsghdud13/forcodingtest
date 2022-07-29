#include <bits/stdc++.h>
using namespace std;

vector <int> adj[102];
bool vis[102];

void dfs(int cur){
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int k;
            cin>>k;
            if(k) adj[i].push_back(j); 
        }
    }
    
    for(int i = 0; i < n; i++){
        fill(vis,vis + n,0);
        dfs(i);
        for(int j = 0; j <n; j++)
            cout<<vis[j]<<" ";
        cout<<'\n';
    }


}