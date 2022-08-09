#include <bits/stdc++.h>
using namespace std;

int d[45];
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= 40; i++){
        d[i] = d[i-1] + d[i-2];
    }
    int idx = 1;
    int answer = 1;
    for(int i = 0; i < m; i++){
        int vip;
        cin>>vip;
        answer *= d[vip-idx];
        idx = vip + 1;
    }
    cout<<answer * d[n-idx+1];
}