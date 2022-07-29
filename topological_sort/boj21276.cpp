#include <bits/stdc++.h>
using namespace std;

int n,m;
string name[1005];
vector <int> adj[1005];
vector <int> save[1005];
vector <int> ancestor;
map <string, int> ms;
int deg[1005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        string x;
        cin>>x;
        name[i] = x;
    }

    sort(name + 1, name + n + 1);

    for(int i = 1; i <= n; i++){
        ms[name[i]] = i;
    }

    cin>>m;
    while(m--){
        string x,y;
        cin>>x>>y;
        adj[ms[y]].push_back(ms[x]);
        deg[ms[x]]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0){
            q.push(i);
            ancestor.push_back(i);
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0){
                q.push(nxt);
                save[cur].push_back(nxt);
            }
        }
    }
    cout<<ancestor.size()<<'\n';
    sort(ancestor.begin(),ancestor.end());
    for(auto anc : ancestor){
        cout<<name[anc]<<' ';
    }
    cout<<'\n';
    for(int i = 1; i <= n; i++){
        cout<<name[i]<<' ';
        cout<<save[i].size()<<' ';
        sort(save[i].begin(),save[i].end());
        for(auto V : save[i]){
            cout<<name[V]<<' ';
        }
        cout<<'\n';
    }
    
}