#include <bits/stdc++.h>
using namespace std;

int n,q;
set <int> M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        int k;
        cin>>k;
        if(k == 1) M.insert(i);
    }
    long long dohyun = 1;
    while(q--){
        int query;
        cin>>query;
        if(query == 1){
            int i;
            cin>>i;
            if(M.find(i) == M.end()) M.insert(i);
            else
                M.erase(i);
        }
        else if(query == 2){
            int x;
            cin>>x;
            dohyun = (dohyun + x) % n;
            if(dohyun == 0) dohyun = n;
        }
        else{
            if(!M.empty()){
                auto iter = M.lower_bound(dohyun);
                if(iter != M.end()){
                    cout<<*iter-dohyun<<'\n';
                }
                else
                    cout<<*M.begin() + n - dohyun<<'\n';
            }
            else
                cout<<-1<<'\n';
        }
    }
}