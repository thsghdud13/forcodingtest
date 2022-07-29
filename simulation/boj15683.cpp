#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int mp1[10][10];
int mp2[10][10];
int n,m;
vector <pair<int,int>> cctv;

void upd (int x, int y, int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || y < 0 || x >= n || y >= m || mp2[x][y] == 6) return;
        if(mp2[x][y] != 0) continue;
        mp2[x][y] = 7;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int mn = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++){
            cin>>mp1[i][j];
            if(mp1[i][j] != 0 && mp1[i][j] != 6)
                cctv.push_back({i,j});
            if(mp1[i][j] == 0)
                mn++;
        }
    for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                mp2[i][j] = mp1[i][j];
        int brute = tmp;
        for(int i = 0; i < cctv.size(); i++){
            int dir = brute %= 4;
            brute /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            if(mp1[x][y] == 1){
                upd(x,y,dir);
            }
            else if(mp1[x][y] == 2){
                upd(x,y,dir);
                upd(x,y,dir+2);
            }
            else if(mp1[x][y] == 3){
                upd(x,y,dir);
                upd(x,y,dir+1);
            }
            else if(mp1[x][y] == 4){
                upd(x,y,dir);
                upd(x,y,dir+1);
                upd(x,y,dir+2);
            }
            else{
                upd(x,y,dir);
                upd(x,y,dir + 1);
                upd(x,y,dir + 2);
                upd(x,y,dir + 3);
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (mp2[i][j] == 0);
        mn = min(mn,val);
    }
    cout<<mn;
}