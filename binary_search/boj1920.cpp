#include <bits/stdc++.h>
using namespace std;

int a[100001];
int n;

int binarysearch(int t){
    int st = 0;
    int en = n-1;
    int mid;
    while(st<=en){
        mid = (st+en)/2;
        if(a[mid] == t) return 1;
        if(a[mid]>t){
            en = mid-1;
        }
        if(a[mid]<t){
            st = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int m;
    cin>>m;
    for(int i = 0; i < m; i++){
        int k;
        cin>>k;
        cout<<binarysearch(k)<<'\n';
    }
    return 0;
}