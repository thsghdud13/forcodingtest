#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
ll d[105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    d[1] = 1, d[2] = 1, d[3] = 1;
    for(int i = 4; i <= 100; i++){
        d[i] = d[i-3] + d[i-2];
    }
    while(t--){
        int n;
        cin>>n;
        cout<<d[n]<<'\n';
    }
}