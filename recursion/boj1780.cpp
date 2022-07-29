#include <bits/stdc++.h>
using namespace std;

int paper[20000][20000];
int ans[3];

bool check(int x, int y, int n){
    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++){
            if(paper[x][y] != paper[i][j])
                return false;
        }
    return true;
}

void func(int x, int y, int n){
    if(check(x,y,n)){
        ans[paper[x][y] + 1] += 1;
        return;
    }
    int k = n/3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            func(x + i * k, y + j * k, k);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>paper[i][j];
    func(0,0,n);
    for(int i = 0; i < 3; i++)
        cout<<ans[i]<<"\n";
}