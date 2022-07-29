#include <bits/stdc++.h>
using namespace std;

int m,n;
vector <int> HL;
//x는 과자길이
bool solve(int x){
    int cur = 0;
    for(auto C:HL){
        cur += C/x;
    }
    if(cur >= m) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        HL.push_back(k);
    }
    sort(HL.begin(),HL.end());

    int st = 0;
    int en = 1000000000;

    while(st<en){
        int mid = (st+en+1)/2;
        if(solve(mid)) st = mid;
        else en = mid-1;
    }
    

    cout<<st;
}