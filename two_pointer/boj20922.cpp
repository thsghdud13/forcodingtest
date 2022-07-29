#include <bits/stdc++.h>
using namespace std;

int n,k;
int arr[200005];
int chk[100005];
const int cs = -9999999;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>arr[i];

    int en = 0;
    chk[arr[en]]++;
    int cnt = 0;
    int mx = cs;

    for(int st = 0; st < n; st++){
        while(en < n-1 && chk[arr[en+1]] < k){
            en++;
            chk[arr[en]]++;
        }
        mx = max(mx, en - st + 1);
        chk[arr[st]]--;
    }
    

    cout<<mx;

}