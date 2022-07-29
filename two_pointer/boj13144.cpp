#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
bool check[100005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];

    int en = 0;
    long long ans = 0;
    check[arr[0]] = 1;
    
    for(int st = 0; st < n; st++){
        while(en < n-1 && !check[arr[en+1]]){
            en++;
            check[arr[en]] = 1;
        }
        ans += (en - st + 1);
        check[arr[st]] = 0;
    }
    cout<<ans;
}