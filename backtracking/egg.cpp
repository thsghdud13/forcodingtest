#include <bits/stdc++.h>
using namespace std;

int n, ans, broken;
int s[10];
int w[10];

void func(int cnt){
    if(cnt == n){
        ans = max(ans,broken);
        return;
    }
    if(s[cnt] <= 0 || broken == n-1){
        func(cnt + 1);
        return;
    }
    for(int i = 0; i < n; i++){
        if(s[i] > 0 && i != cnt){
            s[cnt] -= w[i];
            s[i] -= w[cnt];
            if(s[cnt] <= 0) broken++;
            if(s[i] <= 0) broken++;

            func(cnt + 1);

            if(s[cnt] <= 0) broken--;
            if(s[i] <= 0) broken--;
            s[cnt] += w[i];
            s[i] += w[cnt];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        s[i] = a;
        w[i] = b;
    }
    func(0);
    cout<<ans;
}