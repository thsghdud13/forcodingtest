#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long

const ll INF = 1e18;
int n,m,k;
vector <pair<int,int>> adj[100005];
ll d[100005];
vector <int> t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        adj[v].push_back({c,u});
    }
    while(k--){
        int s;
        cin>>s;
        t.push_back(s);
    }
    fill(d,d+n+1,INF);
    priority_queue < pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
    for(auto cur : t){
        d[cur] = 0;
        pq.push({d[cur],cur});
    }

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
    ll ans = 0;
    int ansnumber = 0;
    for (int i = 1; i <= n; i++)
	{
		if (ans < d[i])
		{
			ans = d[i];
			ansnumber = i;
		}
	}
    cout<<ansnumber<<'\n'<<ans;
    return 0;
}