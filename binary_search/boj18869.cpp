#include <bits/stdc++.h>
using namespace std;

int m,n;
int x[10005];
vector <int> uni[105];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin>>a;
            uni[i].push_back(a);
        }
        sort(uni[i].begin(),uni[i].end());
        uni[i].erase(unique(uni[i].begin(),uni[i].end()),uni[i].end());
        
    }
}