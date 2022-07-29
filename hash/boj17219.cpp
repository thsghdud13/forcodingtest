#include <bits/stdc++.h>
using namespace std;

unordered_map <string,string> K;
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        string site,pwd;
        cin>>site>>pwd;
        K[site] = pwd;
    }
    for(int i = 0; i < m; i++){
        string ans;
        cin>>ans;
        cout<<K[ans]<<'\n';
    }
}