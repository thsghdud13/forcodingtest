#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int friends[205];
int city[205][205];
int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        fill(city[i] + 1, city[i] + n + 1, INF);
    }
    while(m--){
        int a,b,cost;
        cin>>a>>b>>cost;
        city[a][b] = cost;
    }

    for(int i = 1; i <= n; i++)
        city[i][i] = 0;
    
    cin>>k;
    for(int i = 1; i <= k; i++)
        cin>>friends[i];

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                city[i][j] = min(city[i][j],city[i][k] + city[k][j]);
            }

    int min_value = INF;
    vector <int> cities;
    
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        bool check = true;
        for(int j = 1; j <= k; j++){
            if(city[i][friends[j]] == INF || city[friends[j]][i] == INF)
            {
                check = false;
                break;
            }
            tmp = max(tmp , city[friends[j]][i] + city[i][friends[j]]);
        }
        if(check){
            if(tmp < min_value){
                min_value = tmp;
                cities.clear();
                cities.push_back(i);
            }
            else if(tmp == min_value){
                cities.push_back(i);
            }
        }
    }
    for(auto X : cities)
        cout<<X<<" ";
    
}