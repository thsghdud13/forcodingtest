#include <bits/stdc++.h>
using namespace std;

int n,k;
int s[1000005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>s[i];

    int en = 0;
    int odd = 0;
    int mx = 0;

    if(s[0] % 2 != 0) odd++;

    for(int st = 0; st < n; st++){
        while(en < n-1 && odd != k + 1){
            en++;
            if(en == n) break;
            if(s[en]%2 != 0) odd++;
        }
        mx = max(mx,en-st+1 - odd);
        if(s[st] % 2 != 0) odd--;
    }
    cout<<mx;
}