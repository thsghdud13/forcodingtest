#include <bits/stdc++.h>
using namespace std;
int x;
bool visited[1000001];
int dist[1000001];
queue <int> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>x;
    Q.push(x);
    visited[x] = 1;
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int i = 0; i < 3; i++){
            int nx;
            if(i == 0){
                if(cur%3 != 0) continue;
                nx = cur/3; 
            }
            if(i == 1){
                if(cur%2 != 0) continue;
                nx = cur/2;
            }
            if(i == 2){
                nx = cur-1;
            }
            if(nx <= 0) continue;
            if(visited[nx]) continue;
            dist[nx] = dist[cur] + 1;
            visited[nx] = 1;
            Q.push(nx);
        }
        if(dist[1]) break;
    }
    cout<<dist[1];
}