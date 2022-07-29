#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10];
int p[10];
int depth[10];
void dfs(int root){
    stack <int> s;
    s.push(root);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]){
            if(p[cur] == nxt) continue;
            s.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}

// 재귀, 스택메모리 주의


void dfs(int cur){
    cout << cur << " ";
    for(int nxt : adj[cur]){
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}