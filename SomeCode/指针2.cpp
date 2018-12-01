#include <iostream>

using namespace std;

int main()
{
    int *p;
    int num=1;
    p=&num;
    cout<<"&num"<<&num<<endl;
    cout<<"*p"<<*p<<endl;
    cout<<"p"<<p<<endl;
    return 0;

}
