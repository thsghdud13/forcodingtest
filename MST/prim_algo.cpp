#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e;
vector <pair<int,int>> adj[10];
bool chk[10005];
int cnt = 0;

priority_queue < tuple<int,int,int>, vector <tuple<int,int,int>>, greater<tuple<int,int,int>> > pq;

int main(){
    chk[1] = 1;
    for(auto nxt : adj[1]){
        pq.push({nxt.X, 1, nxt.Y});
    }
    while(cnt < v-1){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        cout<<cost<<' '<<a<<' '<<b;
        chk[b] = 1;
        cnt++;
        for(auto nxt : adj[b]){
            if(!chk[nxt.Y])
                pq.push({nxt.X, b ,nxt.Y});
        }
    }
}
