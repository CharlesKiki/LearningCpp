#include<iostream> //判断一个数字是否可以被3和5整除 
using namespace std;
int main()
{
    int n,x,y;
    cout<<"请输入一个数字";
    cin>>n;
    x=n%3;
    y=n%5;
    if (x==0&&y==0)
        cout<<"该数字可以被3和5整除";
        else
        cout<<"这个数字不能被3和5整除";
    return 0;

}
