#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    while(k--){
        int v,e;
        cin>>v>>e;
        vector <int> adj[20005];
        while(e--){
            int x , y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
}