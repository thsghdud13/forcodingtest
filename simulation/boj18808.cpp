#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int r,c;
int note[40][40];
int sticker[12][12];

void rotate(){
    int tmp[12][12];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            tmp[i][j] = sticker[i][j];
    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++){
            sticker[i][j] = tmp[r-1-j][i];
        }
    swap(r,c);
}

bool pastable(int x, int y){
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(note[i + x][j + y] == 1 && sticker[i][j] == 1) 
                return false;
        }
    for(int i = 0; i < r; i++)
        for(int j = 0; j <c; j++){
            if(sticker[i][j] == 1) 
                note[i + x][j + y] = 1;
        }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    while(k--){
        cin>>r>>c;
        for(int a = 0; a < r; a++)
            for(int b = 0; b < c; b++){
                cin>>sticker[a][b];
            }
        
        for(int rot = 0; rot < 4; rot++){
            bool is_paste = false;
            for(int x = 0; x <= n - r; x++){
                if(is_paste) break;
                for(int y = 0; y <= m - c; y++){
                    if(pastable(x,y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate();
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            ans += note[i][j];
        }
    cout << ans;
    return 0;
}