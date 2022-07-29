#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
vector<int> save;
vector<vector<int>> ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        save.push_back(a);
    }
    sort(save.begin(),save.end());
    fill(arr,arr+n,1);
    for(int i = 0; i < m; i++) arr[i] = 0;

    do
    {
        vector<int> tmp;
        for(int i = 0; i < n; i++)
            if(!arr[i]) tmp.push_back(save[i]);
        do
        {
            ans.push_back(tmp);
        } while (next_permutation(tmp.begin(),tmp.end()));
    } while (next_permutation(arr,arr+n));

    sort(ans.begin(),ans.end());
    for(auto a : ans){
        for(auto b: a){
            cout<<b<<' ';
        }
        cout<<'\n';
    }
}