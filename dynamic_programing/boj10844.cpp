#include <bits/stdc++.h>
using namespace std;
long long d[102][10];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    d[1][0] = 0;
    d[1][1] = 1;
    d[1][2] = 1;
    d[1][3] = 1;
    d[1][4] = 1;
    d[1][5] = 1;
    d[1][6] = 1;
    d[1][7] = 1;
    d[1][8] = 1;
    d[1][9] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            if(j == 0){
                d[i][j] = d[i-1][j+1];
            }
            else if(j == 9){
                d[i][j] = d[i-1][j-1];
            }
            else{
                d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
            }
        }
    }
    cout<<(d[n][0] + d[n][1] + d[n][2] + d[n][3] + d[n][4] + d[n][5] + d[n][6] + d[n][7] + d[n][8] + d[n][9]) % 1000000000;
}