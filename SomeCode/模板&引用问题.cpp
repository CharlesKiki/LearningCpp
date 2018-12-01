模板 模板函数 模板类 ------> 标准模板类

友元函数 友元类
全局函数
友元全局函数
成员函数
友元成员函数
class test
{
	friend void test1(test &TEST);
	{
		cout<<TEST.x<<TEST.y;
		//直接访问私有成员
	}	//友元函数关键字
	//传入当前类的一个对象
	//或者一个引用
	public:
	private:
	int  x;
	int  y;
};

Σ(っ °Д °;)っ 静态 数据成员 成员函数

运算符重载  


//引用问题
#include<iostream.h>
void swap(double & d1,double & d2) //d1和d2是引用型变量
{
       double temp ;
       temp=d1 ;
       d1=d2 ;
       d2=temp ;
}

void main(void)
{
       double x , y ;
       cout<<"请输入x和y的值"<<'\n';
       cin>>x>>y ;
       swap(x,y) ;
	   //定义了别名 而 传入变量名
       cout<<"x="<<x<<'\t'<<"y="<<y<<'\n';
}

2 引用可以作为函数的返回值

一般函数返回值时，要生成一个临时变量作为返回值的拷贝，而用引用作为返回值时，不生成值的拷贝。

#include<iostream>
using namespace std;
double temp;
double fsqr1(double a){
    temp=a*a ; return temp;
}
double & fsqr2(double a){
    temp=a*a ; return temp;
}
//取址符 和 函数名的 定义？
&的意思是，返回类型为Complex 的一个引用。
不加&的时候表示，返回类型为Complex 的一个拷贝。
就类似于函数参数传递时，按值传递和按引用传递的区别
int main(){
    double x=fsqr1(5.5);//第一种情况
    double y=fsqr2(5.5);//第二种情况
    cout<<"x="<<x<<'\t'<<"y="<<y<<endl;
    return 0;
}
