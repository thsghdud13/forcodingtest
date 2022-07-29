#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define X first

#define Y second

int n,m,st,en;
ll money;
const ll INF = 1e18+10;
vector <pair<ll,int>> adj[100005];
ll d[100005];

bool dijk (int a, ll cost){
    fill(d,d+1+n,INF);
    priority_queue < pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
    d[a] = 0;
    pq.push({d[a],a});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]){
            if(nxt.X > cost) continue;
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    if(d[en] <= money) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>st>>en>>money;
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        adj[a].push_back({cost,b});
        adj[b].push_back({cost,a});
    }
    ll ans = -1;
	ll l = 0, r = INF;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (!dijk(st,mid))
			l=mid+1;
		else {
			ans = mid;
			r = mid;
		}
	}
	cout << ans;
	return 0;
}