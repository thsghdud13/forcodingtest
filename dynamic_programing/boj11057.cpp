#include <bits/stdc++.h>
using namespace std;

int n;
long long d[1005][10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i = 1; i <= n; i++){
        d[i][0] = 1;
        for(int j =1; j <= 9; j++){
            d[i][j] = (d[i][j-1] + d[i-1][j])%10007;
        }
    }
    int ans = 0;
    for(int i = 0; i <= 9; i++){
        ans = (ans + d[n][i])%10007;
    }
    cout<<ans;
}