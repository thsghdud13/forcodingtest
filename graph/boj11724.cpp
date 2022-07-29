#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1005];
bool vis[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n , m;
    cin>>n>>m;
    while(m--){
        
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    queue <int> q;
    //연결요소 구하기
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        q.push(i);
        vis[i] = true;
        cnt++;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout<<cnt;
}