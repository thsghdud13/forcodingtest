#include <bits/stdc++.h>
using namespace std;

long long d[100];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[0] = 0;
    d[1] = 1;
    
    for(int i = 2; i <= n; i++){
        d[i] = d[i-2] + d[i-1];
    }
    cout<<d[n];
}