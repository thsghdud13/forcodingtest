#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10];
bool vis[10];
void dfs(int cur){
    vis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}
//재귀 dfs -- 스택메모리 주의
//비재귀 dfs와의 차이점 (방문순서가 다름)

vector <int> adj[10];
bool vis[10];
void dfs(){
    stack <int> s;
    s.push(1);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        cout<< cur << ' ';
        for(auto nxt : adj[cur]){
            if(vis[nxt]) continue;
            s.push(nxt);
        }
    }
}
// 수정한 비재귀 dfs - > 관념적으로 생각하는 dfs 와 같음
//사실 dfs 문제는 잘 없다 오일러,bcc 등