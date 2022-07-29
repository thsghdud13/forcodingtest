#include <bits/stdc++.h>
using namespace std;
char board[10000][10000];
int n;
void func(int x, int y, int k){
    if(k == 1){
        board[x][y] = '*';
        return;
    }
    int s = k/3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1) continue;
            func(x + i * s, y + j * s, s);
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    func(0,0,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '*')
                cout<<board[i][j];
            else
                cout<<' ';
        }
        cout<<'\n';
    }

}