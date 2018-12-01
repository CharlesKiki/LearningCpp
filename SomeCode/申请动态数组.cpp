#include <iostream>
using namespace std;

//编写函数申请动态数组
void App(int *&pa,int n)
int main()
{
	int *ary=NULL,*t;
	int i,n;
	cout<<"n=";
	cin>>n;
	App(ary,n);
	for(t=ary;t<ary+n;t++)
		cout<<*t<<" ";
	cout<<endl;
	for(i=0;i<n;i++)
		ary[i]=10+i;
	for(i=0;i<n;i++)
		cout<<ary[i]<<" ";
	cout<<endl;
	delete ary[];
	ary =NULL;
}
void App(int *&pa,int len)  //pa指针引用参数
{
	pa=new int[len];   //动态数组分配
	if(pa==NULL)
	{
		cout<<"allocation faiure/n";
		return ;
	}
	for(int i=0;i<len;i++)  //赋初始值
		pa[i]=0;
}


//4-18 动态分配和释放存储区
int main()
{
	int *p=NULL;  //空值指针变量  注意 指针变量一开始应该初始化
	p=new int;  //申请一个整型空间，地址写入指针变量p
	if(p==NULL)  //判断整型空间是否申请成功
	{
		cout<<"allocationg faiure\n";
		return 0;
	}
	*p =20;
	cout<<*p<<endl;
	delete p;   //释放p所指存储空间
	p=NULL;  //继续赋空值
	return 1;
}







enum colour
{
	red,yellow,blue,white,black
};
int main()
{
	colour c;
	c=red;
	cout<<"Red:"<<c<<endl; //0
	c=blue;
	cout<<"blue:"<<c<<endl; //2
	c=black;
	cout<<"black:"<<c<<endl;  //5
}