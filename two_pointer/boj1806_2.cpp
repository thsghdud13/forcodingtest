#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,s;
ll mn = 0x7fffffff;
ll arr[100005];

ll solve(int x, int y){
    if(x == y) return arr[x];
    ll total = 0;
    for(int i = x; i <= y; i++){
        total += arr[i];
    }
    return total;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i = 0; i < n; i++) cin>>arr[i];
    ll st = 0;
    ll en = 0;
    sort(arr,arr+n);
    while(en<n){
        if(solve(st,en) >= s){
            mn = min(mn, en - st + 1);
            st++;
        }
        else{
            en++;
        }
    }
    if(mn == 0x7fffffff) mn = 0;
    cout<<mn;
}