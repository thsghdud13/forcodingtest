#include <bits/stdc++.h>
using namespace std;

int l,c;
char save[20];
int arr[20];

bool aeiou(char t){
    return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>c;
    for(int i = 0; i < c; i++) cin>>save[i];
    sort(save, save + c);
    vector <int> brute(c);
    for(int i = l; i < c; i++) brute[i] = 1;
    do{
        string ans;
        int cnt1 = 0;
        for(int i = 0; i < c; i++){
            if(brute[i] == 0){
                ans += save[i];
                if(aeiou(save[i])) cnt1++;
            }
        }
        if(cnt1 < 1 || l - cnt1 < 2) continue;
        cout<<ans<<'\n';
    }
    while(next_permutation(brute.begin(),brute.end()));
}