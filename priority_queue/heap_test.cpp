#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수
int n;

void push(int x)
{
    sz++;
    int point = sz;
    heap[point] = x;
    while(heap[point/2] >= heap[point]){
        int tmp = heap[point/2];
        heap[point/2] = heap[point];
        heap[point] = tmp;
        point = point / 2;
    }
    return;
}

int top()
{
    return heap[1];
}

void pop()
{
    if(sz == 0){
        cout<<0<<'\n';
        return;
    }
    cout<<heap[1]<<'\n';;
    heap[1] = heap[sz--];
    int idx = 1;
    while(2*idx <= sz){
        int lc = 2*idx, rc = 2*idx + 1;
        int min_child = lc;
        if(rc <= sz && heap[rc] < heap[lc])
            min_child = rc;
        if(heap[idx] <= heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x == 0){
            pop();
        }
        else{
            push(x);
        }
    }
}