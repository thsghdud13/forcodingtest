#include <bits/stdc++.h>
using namespace std;

int d[1005];
int pre[1005];
int a[1005];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        d[i] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++){
            if(a[i] > a[j] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
    
    int maxi = 1; int maxd = d[1];
    for(int i = 2; i <= n; ++i){
        if(maxd < d[i]){
            maxd = d[i];
            maxi = i;
        }
    }
    int cur = maxi;
    deque <int> m;
    while(cur){
        m.push_front(a[cur]);
        cur = pre[cur];
    }
    cout<<m.size()<<'\n';
    for(auto k : m){
        cout<<k<<' ';
    }
}