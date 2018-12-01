//静态多态=早绑定
//动态多态=晚绑定
class Rect
{
	public:
	int Area(int width);
	int Area(int width,int height);
};
int main(void)
{
	Rect rect;
	rect.Area(10);
	rect.Area(10,20);
	return 0;
}
//编译器自动调动实例化内的重载
//编译器在实例化（编译）时就已经确定了函数使用=早绑定

class Shape  //父类
{
	public:
	virtual double calcArea();//虚函数 实现多态
	{
		cout<<"calcArea"<<endl;
		return 0;
	}
};
class Circle : public Shape
{
	public:
	Circle(double r);
	virtual double calcArea();
	//在子类中实际上不用加上virtual关键字 但是方便观察
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
	//注意防止内存泄露
	return 0;
}
//new 关键字
//C++在创建对象的时候可以采用两种方式：（例如类名为Test） Test test  或者 Test* pTest = new Test()。
//析构函数，删除该对象.
//使用new创建对象是创建在堆中的，必须要程序员手动的去管理该对象的内存空间.
