#include <iostream>

using namespace std;

int main()
{
    int a=2;
    cout<<"The A is 2"<<endl;
    int *p=NULL;  //注意，指针变量的空值初始化
    p=&a;  //对变量的取地址=指针变量名代表的地址
    cout<<"The &A is "<<&a<<endl;
    cout<<"The p is "<<p<<endl;

    int b;
    int *s=&b;  //指针的初始化为变量地址
    b=a;  //注意 这里不是a把地址给了b 而是把值给了b而已
    cout<<"The B is "<<*s<<endl;
    cout<<"The &B is "<<&b<<endl;

    *s=*p;  //*s==2 *p==2  b被直接*s影响
    cout<<"The s is "<<s<<endl;
    cout<<"The p is "<<p<<endl;
    cout<<"The *s is "<<*s<<endl;
    cout<<"The *p is "<<*p<<endl;
    return 0;
}
