#include <bits/stdc++.h>
using namespace std;
int n;

void _bar(const char* str, int stk){
    for(int j = 0; j < stk; j++) cout << "____";
    cout<<str;
}

void func(int k)
{
    _bar("\"����Լ��� ������?\"\n", k);
    if (k == n)
    {
        _bar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", k);
    }
    else
    {
        _bar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", k);
        _bar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", k);
        _bar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", k);
        func(k+1);
    }
    _bar("��� �亯�Ͽ���.\n", k);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cout<<"��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."<<'\n';
    func(0);
}
