#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n,ans,cnt;
vector <pair<int,int>> adj[305];
bool chk[305];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int cost;
        cin>>cost;
        adj[n+1].push_back({cost,i});
        adj[i].push_back({cost,n+1});
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cost;
            cin>>cost;
            if(cost == 0) continue;
            adj[i].push_back({cost,j});
            adj[j].push_back({cost,i});
        }
    }

    priority_queue < tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;
    //cost,a,b
    chk[1] = true;

    for(auto nxt : adj[1]){
        pq.push({nxt.X, 1, nxt.Y});
    }
    while(cnt < n){
        int cost,a,b;
        tie(cost,a,b) = pq.top();
        pq.pop();
        if(chk[b]) continue;
        chk[b] = true;
        ans += cost;
        cnt++;
        for(auto nxt : adj[b]){
            if(chk[nxt.Y]) continue;
            pq.push({nxt.X,b,nxt.Y});
        }
    }
    cout<<ans;
}

