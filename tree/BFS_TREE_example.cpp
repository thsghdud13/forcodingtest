#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10];
int p[10];
void bfs(int root){
    queue <int> q;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";
        for(auto nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
}