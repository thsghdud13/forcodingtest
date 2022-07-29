#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
int p[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    for(int i = 2; i <= n; i++){
        cout<<p[i]<<'\n';
    }
}