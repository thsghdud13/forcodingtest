#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000002];
vector <int> F,V;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        F.push_back(arr[i]);
    }
    sort(F.begin(),F.end());
    int idx = F.front();
    V.push_back(F.front());
    for(int i = 0; i < n; i++){
        if(F[i] == idx) continue;
        else{
            idx = F[i];
            V.push_back(F[i]);
        }
    }
    for(int i = 0; i < n ; i++){
        cout<<lower_bound(V.begin(),V.end(),arr[i]) - V.begin()<<" ";
    }
}