#include <bits/stdc++.h>
using namespace std;
char board[4000][10000];

void func(int k , int x, int y){
    if(k == 3) {
        board[x][y] = '*';
        board[x + 1][y - 1] = '*';
        board[x + 1][y + 1] = '*';
        for(int i = y - 2; i <= y + 2; i++)
            board[x+2][i] = '*';
        return;
    }
    int s = k/2;
    func(s,x,y);
    func(s,x + s, y - s);
    func(s,x + s, y + s);    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    func(n,0,n-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2 - 1; j++){
            if(board[i][j] == '*')
                cout<<'*';
            else   
                cout<<' ';
        }
        cout<<'\n';
    }
}