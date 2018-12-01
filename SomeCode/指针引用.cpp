#include <iostream>
using namespace std;
int main1(void)
{
	int a = 10;
	int *p = &a;
	int *&q = p; //q是一个指针
	*q =20 ;
	cout << a << endl;
	return 0;
}

typedef struct
//关键字 typedef
{
	int x ;
	int y ;
}Coord;
int main(void)
{
	Coord c;
	Coord &c1 = c;
	c1.x = 10 ;
	c1.y = 20 ;
	cout<< c.x<<","<<c.y<<endl;
}
int main2(void)
{
	int a =10;
	int &b =a ;
	//int &b=NULL;
	b = 20;
	cout << a << endl;
	a = 30;
	cout << b <<endl;
	system("pause");
}
//练习
#include <iostream>
using namespace std;
int main(void)
{
    int x = 3;
    //定义引用，y是x的引用
    int &y = x ;
    //打印x和y的值
	cout << y <<endl;
    cout << x <<endl;
	//修改y的值
    y = 4;
    //再次打印x和y的值
    cout << y << endl;
	cout << x <<endl;
	return 0;
}

	