#include <bits/stdc++.h>
using namespace std;
int n;
int board[70][70];

bool check(int x, int y, int k){
    for(int i = x; i < x + k; i++)
        for(int j = y; j < y + k; j++)
        {
            if(board[x][y] != board[i][j])
                return false;
        }
    return true;
}

void func(int x, int y, int k){
    if(check(x,y,k)){
        cout<<board[x][y];
        return;
    }
    cout<<'(';
    int tmp = k/2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            func(x + i * tmp, y + j * tmp, tmp);
        }
    cout<<')';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        string str;
        cin>>str;
        for(int j = 0; j < n; j++)
            board[i][j] = str[j] - '0';
    }
    func(0,0,n);   
}