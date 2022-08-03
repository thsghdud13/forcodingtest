#include <bits/stdc++.h>
using namespace std;

int T,W;
int a[1005];
int d[1005][3][35];
//BFS로 풀수있나?

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T>>W;
    for(int i = 1; i <= T; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= T; i++){
        d[i][1][0] = d[i-1][1][0] + (a[i] == 1 ? 1 : 0);
        for(int j = 1; j <= W; j++){
            if(i < j) break;
            if(a[i] == 1){
                d[i][1][j] = max(d[i-1][2][j-1], d[i-1][1][j]) + 1;
                d[i][2][j] = max(d[i-1][1][j-1],d[i-1][2][j]);
            }
            else{
                d[i][1][j] = max(d[i-1][2][j-1], d[i-1][1][j]);
                d[i][2][j] = max(d[i-1][1][j-1],d[i-1][2][j]) + 1;
            }
        }
    }
    int i1 = *max_element(d[T][1] + 1, d[T][1] + W + 1);
    int i2 = *max_element(d[T][2] + 1, d[T][2] + W + 1);
    cout<<max(i1,i2);
}