#include <bits/stdc++.h>
using namespace std;

int A[100002];
int n,m;
int mn = 0x7fffffff;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    sort(A,A+n);

    int st = 0;
    int en = 0;

    while(en < n){
        if(A[en]-A[st] >= m){
            mn = min(mn, A[en] - A[st]);
            st++;
        }
        else{
            en++;
        }
    }
    cout<<mn;
}