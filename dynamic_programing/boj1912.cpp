#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int d[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a[i];
        d[i] = a[i];
    }
    
    for(int i = 1; i <= n; ++i){
        d[i] = max(d[i] , d[i-1] + a[i]);
    }
    cout<<*max_element(d + 1, d + n + 1);
}