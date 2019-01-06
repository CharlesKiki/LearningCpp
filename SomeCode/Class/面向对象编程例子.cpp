#include<iostream>
using namespace std;
class Cirlce
{
	double radius;
	public:
	//类的成员函数
	void Set_Radius(double r)
	{	radius =r;	}
	doule Get_Radius()
	{	return radius;	}
	double Get_Girth()
	{	return 2*3.14*radius;	}
	double Get_Area()
	{	return 3.14*radius*radius;	}
};
int main ()
{
	Circle A,B;
	A.Set_Radus();
	cout<<"A.Radius="<<A.Get_Radius()<<endl;
	cout<<"A.Girth="<<A.Get_Girth()<<endl;
	cout<<"A.Area="<<A.Get_Area()<<endl;
	B.Set_Radus();
	cout<<"B.Radius"<<B.Get_Radius()<<endl;
	cout<<"B.Girth"<<<B.Get_Girth()<<endl;
	cout<<"B.Area"<<B.Get_Area()<<endl;
}