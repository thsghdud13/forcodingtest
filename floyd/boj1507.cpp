#include <bits/stdc++.h>
using namespace std;

int n;
int d[22][22];
int t[22][22];
bool check = true;
int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            cin>>d[i][j];
            t[i][j] = d[i][j];
        }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                if(k != i && k != j){
                    if(d[i][j] == d[i][k] + d[k][j])
                        t[i][j] = INF;
                }
            }
    int total = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(t[i][j] == INF) continue;
            total += t[i][j];
        }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
            }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(d[i][j] != t[i][j]) check = false;

    if(!check) cout<<-1;
    else cout<<total/2;
}