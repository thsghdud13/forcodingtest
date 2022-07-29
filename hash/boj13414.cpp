#include <bits/stdc++.h>
using namespace std;

int k,l;
const int M = 500005;
const int a = 1000;
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;

int status[M];
int key[M];
int val[M];
int s2i[M];

int my_hash(int &s){
    return (M + s%a) % M;
}

int find(int s){
    int idx = my_hash(s);
    while(status[idx] != EMPTY){
        if(key[idx] == s && status[idx] == OCCUPY) return idx;
        idx = (idx + 1) % M;
    }
    return -1;
}

void insert(int s, int i){
    int idx = find(s);
    if(idx != -1){
        val[idx] = i;
        return;
    }
    idx = my_hash(s);
    while(status[idx] == OCCUPY){
        idx = (idx + 1) % M;
    }
    status[idx] = OCCUPY;
    key[idx] = s;
    val[idx] = i;
}

void erase(int s){
    int idx = find(s);
    if(idx != -1) 
        status[idx] = DUMMY;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(status, status+M, EMPTY);
    cin>>k>>l;
    for(int i = 1; i <= l; i++){
        cin>>s2i[i];
        insert(s2i[i],i);
    }
    int cnt = 0;
    for(int i = 1; i <= l; i++){
        if(cnt >= k) break;
        if(val[find(s2i[i])] == i){
            printf("%08d\n",s2i[i]);
            cnt++;
        }
    }
}