#include <bits/stdc++.h>
using namespace std;

int n,r,q;
vector <int> adj[100002];
vector <int> qu;
int cnt[100002];

int dfs(int cur, int parent){
    int subtreenum = 0;
    for(int nxt : adj[cur]){
        if(nxt == parent) continue;
        subtreenum += dfs(nxt, cur);
    }
    cnt[cur] = subtreenum + 1;
    return cnt[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r>>q;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    while(q--){
        int x;
        cin>>x;
        qu.push_back(x);
    }
    dfs(r,0);
    for(auto cur : qu){
        cout<<cnt[cur]<<'\n';
    }
}