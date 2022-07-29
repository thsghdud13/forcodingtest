#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
int arr[10005];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int en = 0;
    int tot = arr[0];
    for(int st = 0; st < n; st++){
        while(en < n && tot < m){
            en++;
            if(en != n) tot += arr[en];
        }
        if(en == n) break;
        if(tot == m) cnt++;
        tot -= arr[st];
    }
    cout<<cnt;
}