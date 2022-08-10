#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        int d[2][100005];
        int a[2][100005];
        for(int i = 0; i <= 1; i++)
            for(int j = 1; j <= n; j++){
                cin>>a[i][j];
            }
        d[0][1] = a[0][1];
        d[1][1] = a[1][1];
        d[0][2] = a[0][2] + a[1][1];
        d[1][2] = a[1][2] + a[0][1]; 
        for(int i = 3; i <= n; i++){
            d[0][i] = max(d[1][i-1] + a[0][i],d[1][i-2] + a[0][i]);
            d[1][i] = max(d[0][i-1] + a[1][i],d[0][i-2] + a[1][i]);
        }
        cout<<max(d[0][n],d[1][n])<<'\n';
    }
}