#include<iostream> //�ֶκ������� 
using namespace std;
int main()
{
    float x,y;
    cout<<"��Ϊ��������һ���Ա�����";
    cin>>x;
    if(x<1)
        {
        	y=x;
        cout<<y;
		}
    else
        if(1>=x&&x<10)
        {
        	 y=2*x-1;
        cout<<y;
		}
    else
        if(x>=10)
        y=3*x;
        cout<<y;
        return 0;


}
