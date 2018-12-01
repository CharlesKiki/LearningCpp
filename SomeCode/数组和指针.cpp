#include <iostream>
using namespace std;


int main4()
{
	double aa[2]={1.1,2.2},bb[2]={3.3,4.4},cc[2]={5.5,6.6};
	double *pf[3];
	pf[0]=aa;
	pf[1]=bb;
	pf[2]=cc;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<*(pf[i]+j)   //存疑
		}
	}
}
int main3()  //指向基本数组的指针数组
{
	int a=11,b=22,c=33;
	int *pi[3];
	pi[0]=&a;
	pi[1]=&b;
	pi[3]=&c;
	for(int i=0;i<3;i++)
	{
		cout<<*pi[i]<<" "<<endl;
	}
}
int main2()
{
	int a[]={1,3,5,7,9},i,*p;
	for(i=0;i<5;i++)
		cout<<"a["<<i<<"]="a[i]<<endl;
	for(p=a,i=0;i<5;i++)
		cout<<"a["<<i<<"]="<<p[i]<<end
	for(i-0;i<5;i++) //使用指针来访问数组
		cout<<"a["<<i<<"]="<<*(a+i)<<end
	for(p=a;p<a+5;p++)  //使用指针变量间址方式访问数组
		cout<<"a["<<p-a<<"]="<<*p<<end
}
int main1()
{
int wall[N+2][N+2]={{0}};
return o;
}