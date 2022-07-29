#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
int level[100002];
set <int> plebel[102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        int pn,df;
        cin>>pn>>df;
        level[pn] = df;
        plebel[df].insert(pn);
    }
    cin>>m;
    while(m--){
        string O;
        cin>>O;
        if(O == "recommend"){
            int ps;
            cin>>ps;
            if(ps == 1){
                for(int i = 100; i >= 0; i--){
                    if(plebel[i].empty()) continue;
                    cout<<*(prev(plebel[i].end())) << '\n';
                    break;
                }
            }
            else{
                for(int i = 0; i <= 100; i++){
                    if(plebel[i].empty()) continue;
                    cout<<*(plebel[i].begin()) << '\n';
                    break;
                }
            }
        }
        else if(O == "add"){
            int ps,df;
            cin>>ps>>df;
            level[ps] = df;
            plebel[df].insert(ps);
        }
        else{
            int ps;
            cin>>ps;
            plebel[level[ps]].erase(ps);
        }
    }
}