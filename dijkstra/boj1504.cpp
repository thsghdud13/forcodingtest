#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
vector <pair<int,int>> adj[805];
int d[805];
int n,m,first,second;
long long ans1, ans2;
int INF = 0x3f3f3f3f;

int dijkstra(int x, int y){
    priority_queue < pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>> > pq;
    d[x] = 0;
    pq.push({d[x],x});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    return d[y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }
    cin>>first>>second;
    fill(d,d+n+1,INF);
    ans1 += dijkstra(1,first);
    fill(d,d+n+1,INF);
    ans1 += dijkstra(first,second);
    fill(d,d+n+1,INF);
    ans1 += dijkstra(second,n);
    fill(d,d+n+1,INF);
    ans2 += dijkstra(1,second);
    fill(d,d+n+1,INF);
    ans2 += dijkstra(second,first);
    fill(d,d+n+1,INF);
    ans2 += dijkstra(first,n);
    ans1 = min(ans1,ans2);
    if(ans1 >= INF) cout<<-1;
    else cout<<ans1;
}