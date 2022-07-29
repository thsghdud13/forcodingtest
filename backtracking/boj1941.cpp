#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[5];
int ans;
bool mask[25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++){
        cin>>board[i];
    }
    fill(mask + 7, mask + 25, true);

    do{
        queue <pair<int,int>> Q;
        int das = 0, adj = 0;
        bool isp7[5][5] = {}, vis[5][5] = {};
        for(int i = 0; i < 25; i++)
            if(!mask[i]){
                int x = i / 5, y = i % 5;
                isp7[x][y] = true;
                if(Q.empty()) {
                    Q.push({x,y});
                    vis[x][y] = true;
                } 
            }
        
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            adj++;
            if(board[cur.X][cur.Y] == 'S') das++;
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(vis[nx][ny]) continue;
                if(!isp7[nx][ny]) continue;
                if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                vis[nx][ny] = true;
                Q.push({nx,ny});
            }
        }
        if(das >=4 && adj == 7) ans++;
    }
    while(next_permutation(mask,mask + 25));

    cout<<ans;
}