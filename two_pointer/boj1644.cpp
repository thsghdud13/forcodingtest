#include <bits/stdc++.h>
using namespace std;

int k,cnt;

const int MXN = 4000005;

vector <bool> state(MXN,true);
vector <int> primes;

void sieve(int n){
    state[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!state[i]) continue;
        for(int j = i*i; j <= n; j += i)
        state[j] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;

    state[1] = false;
    for(int i = 2; i*i <= MXN; i++){
        if(!state[i]) continue;
        for(int j = i*i; j <= MXN; j += i)
        state[j] = false;
    }

    for(int i = 2; i < MXN; i++){
        if(state[i]) primes.push_back(i);
    }

    int en = 0;
    int tot = primes[0];
    int size = primes.size();
    

    for(int st = 0; st < size; st++){
        while(en < size && tot < k){
            en++;
            if(en != size) tot += primes[en];
        }
        if(en == size) break;
        if(tot == k) cnt++;
        tot -= primes[st];
    }
    cout<<cnt;
}