#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n,m;
int town[102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        fill(town[i] + 1, town[i] + 1 + n, INF);
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        town[a][b] = min(town[a][b], cost);
    }
    for(int i = 1; i <= n; i++){
        town[i][i] = 0;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                town[i][j] = min(town[i][j], town[i][k] + town[k][j]);//시간줄이는 테크닉 : 대입을 적게 해라 min사용 금지
    

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(town[i][j] == INF) cout << "0 ";
            else cout<<town[i][j]<<' ';
        }
        cout<<'\n';
    }
}