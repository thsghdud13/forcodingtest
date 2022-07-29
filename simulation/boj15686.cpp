#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n,m;
int ans = 1500;
int board[51][51];
vector <pair<int,int>> chicken;
vector <pair<int,int>> house;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
             cin>>board[i][j];
            if(board[i][j] == 2){
                chicken.push_back({i,j});
            }
            if(board[i][j] == 1){
                house.push_back({i,j});
            }
        }
    vector <int> brute(chicken.size(),1);
    fill(brute.begin(),brute.end()-m, 0);
    do{
        int CD = 0;
        for (auto h : house){
            int mn = 0x7f7f7f7f;
            for (int i = 0; i < chicken.size(); i++){
                if (brute[i] == 0) continue;
                int tmp = abs(h.X - chicken[i].X) + abs(h.Y - chicken[i].Y);
                mn = min(mn, tmp);
            }
            CD += mn;
        }
        ans = min(ans,CD);
    }
    while(next_permutation(brute.begin(),brute.end()));
    cout<<ans;
}