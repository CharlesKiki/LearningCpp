#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double r,h,s1,s2,s3,v1,v2;  //�ܳ�s1 Բ���s2 Բ������s3 Բ�����v1 Բ�����v2
    cout<<"Please enter the Ball's r and h";
    cin>>r>>h;
    s1=2*3.14*r;
    s2=3.14*r*r;
    s3=4*3.14*r*r;
    v1=3.14*r*r*h;
    v2=s2*h;
    cout<<"�ܳ��� Բ����� Բ�������� Բ������� Բ�������"<<s1<<s2<<s3<<v1<<v2;
}
