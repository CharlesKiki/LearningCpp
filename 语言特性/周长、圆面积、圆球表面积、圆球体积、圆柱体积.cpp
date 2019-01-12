#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double r,h,s1,s2,s3,v1,v2;  //周长s1 圆面积s2 圆球表面积s3 圆球体积v1 圆柱体积v2
    cout<<"Please enter the Ball's r and h";
    cin>>r>>h;
    s1=2*3.14*r;
    s2=3.14*r*r;
    s3=4*3.14*r*r;
    v1=3.14*r*r*h;
    v2=s2*h;
    cout<<"周长是 圆面积是 圆球表面积是 圆球体积是 圆柱体积是"<<s1<<s2<<s3<<v1<<v2;
}
