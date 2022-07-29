#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m,st,en;
vector <pair<int,int>> adj[1005];
int d[1005];
int INF = 1e9+10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].push_back({cost,b});
    }
    cin>>st>>en;
    fill(d,d+n+1,INF);
    priority_queue < pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    cout<<d[en];
}