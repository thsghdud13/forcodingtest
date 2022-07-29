#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        multiset <int> Q;
        while(k--){
            char com;
            cin >> com;
            if(com == 'D'){
                int q;
                cin >> q;
                if(Q.empty()) continue;
                if(q == 1) Q.erase(prev(Q.end()));
                else Q.erase(Q.begin());// 만약에 Q.erase(*Q.begin()) 으로 쓴다면 모든 값 삭제
            }
            else{
                int q;
                cin >> q;
                Q.insert(q);
            }
        }
        if(Q.empty()) cout << "EMPTY" <<'\n';
        else{
            cout<<*prev(Q.end()) << ' ' << *Q.begin() << '\n';
        }
    }
}