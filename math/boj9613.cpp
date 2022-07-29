#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        vector <int> arr;
        int k;
        long long total = 0;
        cin>>k;
        for(int i = 0; i<k; i++){
            int s;
            cin>>s;
            arr.push_back(s);
        }
        for(int i = 0; i < k; i++){
            for(int j = i + 1; j < k; j++){
                total += gcd(arr[i],arr[j]);
            }
        }
        cout<<total<<'\n';
    }
    return 0;
}