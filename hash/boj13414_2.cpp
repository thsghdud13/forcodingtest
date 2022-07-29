#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int k,l;
unordered_map <int, int> D;
int save[1000003];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>l;
    for(int i = 0; i < l; i++){
        cin>>save[i];
        D[save[i]] = i;
    }
    int cnt = 0;
    for(int i = 0; i < l; i++){
        if(cnt >= k) break;
        if(D[save[i]] == i){
            printf("%08d\n",save[i]);
            cnt++;
        }
    }
}