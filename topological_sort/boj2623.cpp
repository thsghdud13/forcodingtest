#include <bits/stdc++.h>
using namespace std;

int n,m;
vector <int> adj[1003];
vector <int> ans;
int deg[1003];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int od[1000];
        int v;
        cin>>v;
        for(int i = 0; i < v; i++){
            cin>>od[i];
        }
        for(int i = 0; i < v-1; i++){
            adj[od[i]].push_back(od[i+1]);
            deg[od[i+1]]++;
        }
    }

    queue <int> q;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    if(ans.size() == n){
        for(auto C : ans) cout<<C<<'\n';
    }
    else{
        cout<<0;
    }
}