#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
string board1[15];
char board2[15][15];
pair<int,int> red;
pair<int,int> blue;
pair<int,int> hole;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};

void tilt(int dir){
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>board1[i];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(board1[i][j] == 'R')
                red = {i,j};
            else if(board1[i][j] == 'B')
                blue = {i,j};
            else if(board1[i][j] == 'O')
                hole = {i,j};
            else
                continue;
        }
    for(int tmp = 0; tmp < (1<<(2*10)); tmp++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        int cnt = 0;
        int mn = 15;
        for(int i = 0; i < 10; i++){
            int dir = brute % 4;

        }
    }
}