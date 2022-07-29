#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 1;
    while(true){
        int L,P,V;
        cin>>L>>P>>V;
        if(L==0 && P==0 && V==0) break;
        cout<<"Case "<<cnt++<<": "<< V / P * L + min(V % P,L)<<"\n";
    }
    return 0;
}