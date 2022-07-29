#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1002];
vector <int> twosum ;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            twosum.push_back(arr[i]+arr[j]);
        }
    }
    sort(twosum.begin(),twosum.end());
    for(int i = n-1; i >= 0; i--)
        for(int j = 0; j < i; j++){
            if(binary_search(twosum.begin(),twosum.end(),arr[i] - arr[j])){
                cout<<arr[i];
                return 0;
            }
        }
}