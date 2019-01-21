#include<iostream>
using namespace std;
/*
	程序功能：测试程序的方法实例化时期
*/

/*
	类 Rect 矩形和长宽参数
	方法Area(int width);
	方法Area(int width,int height);重载
*/
class Rect
{
	public:
	int Area(int width);
	int Area(int width,int height);
};
/*
	测试用例：
	硬编码写入参数的情况下：编译器自动调动实例化内的重载
    编译器在实例化（编译）时就已经确定了函数使用，早绑定
*/
int Example(void)
{
	Rect rect;
	rect.Area(10);
	rect.Area(10,20);
	return 0;
}

/*
	类Shape 
	虚函数calcArea();
*/
class Shape
{
	public:
			virtual double calcArea();
			{
				cout<<"calcArea"<<endl;
				return 0;
			}
};
/*
	类Circle 继承 Shape 
	子类实现方法Circle(double r);
	虚函数calcArea()重载。
	注：在子类中实际上不用加上virtual关键字 但是方便观察
*/
class Circle : public Shape
{
	public:
			Circle(double r);
			virtual double calcArea();
	private:
			double m_dR;
};
double Circle::calcArea()
{
	return 3.14*m_dR*m_dR;
};
class Rect : public Shape
{
	public:
	Rect(double width,double height);
	virtual double calcArea();
	private:
	double m_dWidth;
	double m_dHeight;
};
double Rect::calcArea()
{
	return m_dWidth * m_dHeight;
};
int main(void)
{
	Shape *shape1 = new Circle(4.0);
	Shape *shape2 = new Rect(3.0,5.0);
	shape1->calcArea();
	shape2->calcArea();
	delete shape1;
	delete shape2;
	//注意防止内存泄露，new delete方法成对使用
	return 0;
}