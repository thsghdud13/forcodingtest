#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[500002],b[500002];
vector <int> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    sort(b,b+m);
    sort(a,a+n);

    for(int i = 0; i < n; i++){
        if(binary_search(b,b+m,a[i])) continue;
        else{
            cnt++;
            ans.push_back(a[i]);
        }
    }
    if(cnt == 0){
        cout<<0;
        return 0;
    }
    cout<<cnt<<"\n";
    for(auto C:ans) cout<<C<<" ";
}