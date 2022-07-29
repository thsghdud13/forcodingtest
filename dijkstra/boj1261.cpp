#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[105][105];
string maze[105];
int d[105][105];
int n,m;
const int INF = 1e9+10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string s;
    for(int i = 0; i < m; i++)
        cin>>maze[i];
    
    queue <pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 1;
    
    for(int i = 0; i < m; i++)
        fill(d[i], d[i] + n, INF);
    d[0][0] = 0;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if(maze[nx][ny] == '1'){
                if(d[nx][ny] > d[cur.X][cur.Y] + 1){
                    d[nx][ny] = d[cur.X][cur.Y] + 1;
                    q.push({nx,ny});
                }
            }
            else if(maze[nx][ny] == '0'){
                if(d[nx][ny] > d[cur.X][cur.Y]){
                    d[nx][ny] = d[cur.X][cur.Y];
                    q.push({nx,ny});
                }
            }
        }

    }

    cout<<d[m-1][n-1];
}