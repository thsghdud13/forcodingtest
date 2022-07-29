#include <bits/stdc++.h>
using namespace std;

int n ,m, truth;
vector <int> tp;
vector <int> adj[52];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>truth;
    while(truth--){
        int x;
        cin>>x;
        tp.push_back(x);
    }
    for(int i = 1; i <= n; i++){
        int c;
        cin>>c;
        while(c--){
            int x;
            cin>>x;
            
            adj[i].push_back(x);
        }
        for(auto k : adj[i])
    }

}