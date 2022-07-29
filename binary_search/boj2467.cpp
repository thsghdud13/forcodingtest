#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int sol[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>sol[i];
    }
    int ans1 = 1e9+1;
    int ans2 = 1e9+1;
    for(int i = 0; i < n; i++){
        int idx = lower_bound(sol,sol+n,-sol[i]) - sol;
        if(idx +
         1 < n && i != idx + 1 && abs(sol[i] + sol[idx + 1]) < abs(ans1 + ans2)){
            ans1 = sol[i];
            ans2 = sol[idx + 1];
        }
        if(idx < n && i != idx && abs(sol[i] + sol[idx]) < abs(ans1 + ans2)){
            ans1 = sol[i];
            ans2 = sol[idx];
        }
        if(idx != 0 && i != idx - 1 && abs(sol[i] + sol[idx - 1]) < abs(ans1 + ans2)){
            ans1 = sol[i];
            ans2 = sol[idx-1];
        }
    }
    if(ans1 > ans2) swap(ans1,ans2);
    cout<<ans1<<' '<<ans2;
}