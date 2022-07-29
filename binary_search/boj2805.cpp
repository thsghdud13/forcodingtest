#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
vector <int> Tree;

bool solve(ll x){
    ll cur = 0;
    for(auto C:Tree){
        if(C>x)
            cur += C-x;
    }
    if(cur >= m) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    
    for(int i = 0; i < n; i++) {
        int k;
        cin>>k;
        Tree.push_back(k);
    }
    ll st = 0;
    ll en = *max_element(Tree.begin(),Tree.end());
    
    while(st<en){
        ll mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }
    cout<<st;
}