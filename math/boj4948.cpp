#include <bits/stdc++.h>
using namespace std;

const int k = 123456*2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector <bool> state(k + 1,true);
    state[1] = false;
    for(int i = 2; i*i <= k; i++){
        if(!state[i]) continue;
        for(int j = i*i; j <= k; j += i){
            state[j] = false;
        }
    }
    

    while (true)
    {
        int n,cnt = 0;
        cin >> n;
        if(n==0) return 0;
        for(int i = n+1; i <= 2*n; i++){
            if(state[i]) cnt++;
        }
        cout<<cnt<<'\n';
    }
}