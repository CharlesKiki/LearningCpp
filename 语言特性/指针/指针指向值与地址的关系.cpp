#include <iostream>

using namespace std;

int main()
{
    int a=2;
    cout<<"The A is 2"<<endl;

    int *p=NULL;    
    p=&a;           
    cout<<"The &A is "<<&a<<endl;
    cout<<"The p is "<<p<<endl;

    
    int b;
    int *s=&b;
    b=a;  
    cout<<"The B is "<<*s<<endl;
    cout<<"The &B is "<<&b<<endl;

    *s=*p;  //*s==2 *p==2  b被直接*s影响
    cout<<"The s is "<<s<<endl;
    cout<<"The p is "<<p<<endl;
    cout<<"The *s is "<<*s<<endl;
    cout<<"The *p is "<<*p<<endl;
    return 0;
}
