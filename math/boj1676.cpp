#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ten = 0, five = 0, two = 0;
    cin>>n;
    for(int i = n; i > 1; i--){
        int k = i;
        while(1){
            if(k%10 == 0){
                k = k/10;
                ten++;
            }
            else if(k%5 == 0){
                k = k/5;
                five++;
            }
            else if(k%2 == 0){
                k = k/2;
                two++;
            }
            else
                break;
        }
    }
    if(five >= 1 && two >= 1){
        cout<<ten + min(five,two);
    }
    else{
        cout<<0;
    }
}
//수정사항: 결국엔 5의 개수만 세면 되는 일이다. 간단한 길을 생각해보자.