#include <bits/stdc++.h>
using namespace std;

int d[1005][3];
int s[1005][3];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>s[i][0]>>s[i][1]>>s[i][2];
    }
    d[1][0] = s[1][0];
    d[1][1] = s[1][1];
    d[1][2] = s[1][2];
    for(int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1],d[i-1][2]) + s[i][0];
        d[i][1] = min(d[i-1][0],d[i-1][2]) + s[i][1];
        d[i][2] = min(d[i-1][0],d[i-1][1]) + s[i][2];
    }
    int mn = 0x7f7f7f7f;
    for(int i = 0; i < 3; i++){
        mn = min(mn,d[n][i]);
    }
    cout<<mn;
}
