#include <iostream>
#include <stdlib.h>
using namespace std;

class A {
private:
	//test没有作用，只是占用一定空间，用来观察声明方式占用内存大小
	int test = 24;
	int i;
public:
	A() { cout << "调用没有参数的构造函数" << endl; }
	/*
		commit：这是一种成员函数用冒号给私有变量赋值的方法。
	*/
	int Test() 
	{
		return i;
	}
	A(int a) :i(a) { cout << "调用有一个参数的构造函数" << endl; }
	~A() { cout << "成员变量为:" << i << "\t调用析构函数" << endl; }
};

void main() {
	A a0;           	//形式一：直接声明一个对象 ,栈中
	/*
		注：在声明对象时直接对对象名传参
	*/
	A a1(1);        	//形式二：隐式调用A带一个参数的构造函数,栈中
	A a2 = A(2);        //形式三：显式调用A带一个参数构造函数,栈中
	A *p = new A(10);    //形式四：动态分配，堆中，特征是new
	A* p2 = NULL;
	/*
		commit:利用指针指向的对象，利用delete作用在指针。之后对悬垂指针处理。堆的内存手动管理。
	*/
	cout << "the size of A a0 :" << sizeof(a0) << endl;
	cout << "the size of A a1(1) :" << sizeof(a1) << endl;
	cout << "the size of A a2 = A(2) :" << sizeof(a2) << endl;
	cout << "the size of A *p = new A(3) :" << sizeof(*p) << endl;
	cout << "the size of A *p2  :" << sizeof(*p2) << endl;
	cout << "Test is " << p->Test() << endl;
	//cout << "Test is " << p2->Test() << endl;
	delete p;
	p = NULL;
	/*
		注：无论哪种声明方式最后都会实际申请内存大小，只要使用了构造函数。
			但是，如果是A *p;的方式也会申请内存大小，只是内部没有初始化,这相当于内部的int等都没有写入内存
			此时访问内部成员就会是引发了异常: 读取访问权限冲突。 **this** 是 nullptr。
			也就是这个显式出来的大小只是指针告诉操作系统接下来多少的内存是要读取的对象。
			1.当使用delete时，会对堆上的对象调用析构函数
			2.栈上的对象~A()会在main结束时调用
	*/
	system("pause");
}