#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
string board[15];
pair<int,int> red;
pair<int,int> blue;
pair<int,int> hole;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0 ,0};
int dist[11][11][11][11];

int bfs(){
    queue<tuple<int,int,int,int>> q;
    q.push({red.X,red.Y,blue.X,blue.Y});
    dist[red.X][red.Y][blue.X][blue.Y] = 0;
    while(!q.empty()){
        int rx,ry,bx,by;
        tie(rx,ry,bx,by) = q.front();
        q.pop();
        if (dist[rx][ry][bx][by] >= 10) return -1;
        for(int i = 0; i < 4; i++){
            int mrx = rx,mry = ry,mbx = bx,mby = by;
            while(board[mbx + dx[i]][mby + dy[i]] == '.'){
                mbx += dx[i];
                mby += dy[i];
            }
            if(board[mbx + dx[i]][mby + dy[i]] == 'O') continue;

            while(board[mrx + dx[i]][mry + dy[i]] == '.'){
                mrx += dx[i];
                mry += dy[i];
            }
            if(board[mrx + dx[i]][mry + dy[i]] == 'O')
                return dist[rx][ry][bx][by] + 1;
            
            if(mrx == mbx && mry == mby){
                if(i == 0){
                    ry > by ? mry++ : mby++; 
                }
                else if(i == 1){
                    ry < by ? mry-- : mby--; 
                }
                else if(i == 2){
                    rx > bx ? mrx++ : mbx++; 
                }
                else{
                    rx < bx ? mrx-- : mbx--; 
                }
            }
            if(dist[mrx][mry][mbx][mby] != -1) continue;
            dist[mrx][mry][mbx][mby] = dist[rx][ry][bx][by] + 1;
            q.push({mrx,mry,mbx,mby});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>board[i];
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'R'){
                red = {i,j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'B'){
                blue = {i,j};
                board[i][j] = '.';
            }
            else
                continue;
        }
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 10; k++)
                fill(dist[i][j][k], dist[i][j][k]+10, -1);
            
    cout<<bfs();
}