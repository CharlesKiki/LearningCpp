int main(void)
{
	Shape *shape1 = new Circle(3,5,4.0);  // 注意new申请的是栈还是内存
	// new 可以返回一个指针
	shape1 -> calcArea(); //通过父类指针操纵子类函数
	delete shape1;  //执行父类的析构函数 
	shape1 = NULL;  //为什么删除了shape1 还可以对其赋予空值？
	//删除指针后，该指针变成悬垂指针（dangling pointer）.
	return 0;
}
Circle::Circle(int x,int y,double r)
{
	m_pCenter = new Coordinate(x,y); //注意在构造函数内存在一段请求内存分配
	m_dR = r ;
}
Circle::~Circle()
{
	delete m_pCenter;
	m_pCenter = NULL;
}

//虚析构函数
class Shape
{
	public:
	Shape();
	virtual double calcArea();
	virtual ~Shape();
};
//继承
class Circle : public Shape
{
	public:
	Circle(int x ,int y ,double r);
	virtual ~Circle();
	virtual double calcArea();
	private:
	double m_dR;
	Coordinate *m_pCenter;
};