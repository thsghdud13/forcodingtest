#include <bits/stdc++.h>
using namespace std;

int n;
long long d[95][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1][1] = 1;
    d[1][0] = 0;
    d[2][0] = 1;
    d[2][1] = 0;
    for(int i = 3; i <= n; i++){
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];  
    }
    cout<<d[n][1] + d[n][0];
}