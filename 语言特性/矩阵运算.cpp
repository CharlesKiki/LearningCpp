#include <iostream>

using namespace std;

int main()
{
    int Mat1[3][3]={0};
    int Mat2[3][3]={0};
    int Mat3[3][3]={0};
    cout<<"�����һ������"<<endl;
    for(int i=0;i<=2;i++)
    {
        for(int n=0;n<=2;n++)
        {
            cin>>Mat1[i][n];
        }
    }
    cout<<"����ڶ�������"<<endl;
    for(int i=0;i<=2;i++)
    {
        for(int n=0;n<=2;n++)
        {
            cin>>Mat2[i][n];
        }
    }
    for(int i=0;i<=2;i++)
    {
        for(int n=0;n<=2;n++)
        {
            Mat3[i][n]=Mat1[i][n]+Mat2[i][n];
        }
    }
    cout<<"����¾���"<<endl;
    for(int i=0;i<=2;i++)
    {
        for(int n=0;n<=2;n++)
        {
            cout<<Mat3[i][n]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
