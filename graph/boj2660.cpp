#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> adj[55];
int dist[55];
int score[55]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(1){
        int v,u;
        cin>>v>>u;
        if(v == -1) break;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        fill(dist + 1, dist + n + 1, -1);
        queue <int> q;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : adj[cur]){
                if(dist[nxt] >= 0) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
        score[i] = *max_element(dist,dist+ n + 1);
    }
    int idx = *min_element(score + 1, score + n + 1);
    int cnt = 0;
    vector <int> kings;
    for(int i = 1; i <= n; i++){
        if(idx == score[i]){
            cnt++;
            kings.push_back(i);
        }
    }
    cout<<idx<<" "<<cnt<<'\n';
    for(auto c : kings)
        cout<<c<<" ";
}