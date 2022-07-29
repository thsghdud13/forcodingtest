#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10];
int deg[10];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    vector <int> result;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    if(result.size() != n)
        cout << "cycle exists";
    else{
        for(auto x : result) cout << x << ' ';
    }
}
//시간복잡도 O(V+E)
