#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, k;
pair <int,int> J[300003];
multiset <int> B;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    
    
    for(int i = 0; i < n; i++){
        cin>>J[i].Y>>J[i].X;
    }
    sort(J,J+n);
    for(int i = 0; i < k; i++){
        int c;
        cin>>c;
        B.insert(c);
    }
    long long ans = 0;

    for(int i = n-1; i >= 0; i--){
        int M,V;
        tie(V,M) = J[i];
        auto it = B.lower_bound(M);
        if(it == B.end()) continue;
        ans += V;
        B.erase(it);
    }
    cout<< ans;
}