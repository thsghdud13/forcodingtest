#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
vector <int> save;
vector <int> k;

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
    for(int i = 0; i < n; i++) k.push_back(i < m ? 0 : 1);
    do{
        vector <int> tmp;
        for(int i = 0; i < n; i++){
            if(!k[i]) tmp.push_back(save[i]);
        }
        sort(tmp.begin(),tmp.end());
        for(auto a : tmp){
            cout<<a<<' ';
        }
        cout<<'\n';
    }
    while(next_permutation(k.begin(),k.end()));
}