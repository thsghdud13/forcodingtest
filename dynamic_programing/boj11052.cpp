#include <bits/stdc++.h>
using namespace std;

int d[1005];
int p[1005];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>p[i];
    }
    d[1] = p[1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            d[i] = max({d[i-j] + p[j] , p[i], d[i]});
        }
    }
    cout<<d[n];
}