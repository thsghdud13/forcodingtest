#include <bits/stdc++.h>
using namespace std;

int n;
int power[25][25];
bool isused[25];
int mn = 0x7fffffff;

void calculate(){
    int total1 = 0;
    int total2 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(isused[i] && isused[j]){
                total1 += power[i][j] + power[j][i];
            }
            else if(!isused[i] && !isused[j]){
                total2 += power[i][j] + power[j][i];
            }
        }
    }    
    
    mn = min(mn,abs(total1-total2));
}

void func(int k){
    
    if(k==n/2){
        calculate();
        return;
    }

    for(int i = 1; i <= n; i++){
        isused[i] = 1;
        func(k+1);
        isused[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>power[i][j];

    func(0);
    cout<<mn;
}