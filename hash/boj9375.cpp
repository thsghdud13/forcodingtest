#include <bits/stdc++.h>
using namespace std;

int c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c;
    while(c--){
        int n,cnt = 1;
        unordered_map<string,int> Clothes;
        cin>>n;
        for(int i = 0; i < n; i++){
            string CL,KI;
            cin>>CL>>KI;
            Clothes[KI]++;
        }
        for(auto C:Clothes) cnt *= C.second + 1;
        cout<<cnt-1<<'\n';
    }
}