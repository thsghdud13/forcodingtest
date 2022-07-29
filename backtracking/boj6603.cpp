#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        int k;
        int s[15];
        int arr[15];
        vector <int> a;
        cin>>k;
        if(k == 0) break;
        for(int i = 0; i < k; i++){
            cin>>s[i];
        }
        for(int i = 0; i < k; i++) a.push_back(i < 6 ? 0 : 1);
        do{
            for(int i = 0; i < k; i++){
                if(!a[i]) cout<<s[i]<<' ';
            }
            cout<<'\n';
        }
        while(next_permutation(a.begin(),a.end()));
        cout<<'\n';
        
    }
}