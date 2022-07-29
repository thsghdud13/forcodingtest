#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m, mn;
int board[10][10];
int cp[10][10];
vector <pair<int,int>> CCTV;
int dx[4] = {1 ,0 ,-1 ,0};
int dy[4] = {0 ,1 ,0 ,-1};

void upd(int x, int y, int dir){
    dir = dir % 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(board[x][y] == 6 || x < 0 || y < 0 || x >= n || y >= m) return;
        if(board[x][y] != 0) continue;
        cp[x][y] = 7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin>>board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6)
                CCTV.push_back({i,j});
            if(board[i][j] == 0)
                mn++;
        }
    
    for(int tmp = 0; tmp < (1<<(2*CCTV.size())); tmp++){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                cp[i][j] = board[i][j];
            }
        int brute = tmp;
        for(int i = 0; i < CCTV.size(); i++){
            int dir = brute % 4;
            brute /= 4;
            int x = CCTV[i].X;
            int y = CCTV[i].Y;
            if(board[x][y] == 1){
                upd(x,y,dir);
            }
            if(board[x][y] == 2){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }
            if(board[x][y] == 3){
                upd(x,y,dir);
                upd(x,y,dir+1);
            }
            if(board[x][y] == 4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            if(board[x][y] == 5){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
                upd(x,y,dir+3);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                cnt += (cp[i][j] == 0);
            }
        mn = min(mn,cnt);
    }
    cout<<mn;
    return 0;
}