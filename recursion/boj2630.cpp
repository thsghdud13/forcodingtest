#include <bits/stdc++.h>
using namespace std;
int paper[150][150];
int ans[2];
int n;

bool check(int x, int y, int k){
    for(int i = x; i < x + k; i++)
        for(int j = y; j < y + k; j++)
        {
            if(paper[x][y] != paper[i][j])
                return false;
        }
    return true;
}

void func(int x, int y, int k){
    if(check(x,y,k)){
        ans[paper[x][y]]++;
        return;
    }
    int s = k/2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++){
            func(x + i*s, y + j*s, s);
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>paper[i][j];
    func(0,0,n);
    for(int i = 0; i < 2; i++)
        cout<<ans[i]<<'\n';
}