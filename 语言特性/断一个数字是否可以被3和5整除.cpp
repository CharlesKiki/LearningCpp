#include<iostream> //�ж�һ�������Ƿ���Ա�3��5���� 
using namespace std;
int main()
{
    int n,x,y;
    cout<<"������һ������";
    cin>>n;
    x=n%3;
    y=n%5;
    if (x==0&&y==0)
        cout<<"�����ֿ��Ա�3��5����";
        else
        cout<<"������ֲ��ܱ�3��5����";
    return 0;

}
