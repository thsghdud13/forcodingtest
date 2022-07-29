#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m,x;
vector <pair<int,int>> adj[1005];
int go[1005];
int come[1005];
int INF = 1e9+10;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>x;
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].push_back({cost,b});
    }

    fill(go,go+n+1,INF);
    priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    go[x] = 0;
    pq.push({go[x],x});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(go[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]){
            if(go[nxt.Y] <= go[cur.Y] + nxt.X) continue;
            go[nxt.Y] = go[cur.Y] + nxt.X;
            pq.push({go[nxt.Y],nxt.Y});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        fill(come,come+n+1,INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        come[i] = 0;
        q.push({come[i], i});
        while (!q.empty())
        {
            auto cur = q.top();
            q.pop();
            if (come[cur.Y] != cur.X)
                continue;
            for (auto nxt : adj[cur.Y])
            {
                if (come[nxt.Y] <= come[cur.Y] + nxt.X)
                    continue;
                come[nxt.Y] = come[cur.Y] + nxt.X;
                q.push({come[nxt.Y], nxt.Y});
            }
        }
        go[i] += come[x];
    }
    cout<<*max_element(go+1,go+n+1);
}