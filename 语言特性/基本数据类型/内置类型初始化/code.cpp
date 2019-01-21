#include <iostream>
#include <stdlib.h>
using namespace std;

/*
	commit：内置类型的new初始化方法，类似构造函数，
	但是在内存中的大小还是int的4byte
*/


void main() {
	int *number1 = new int;
	int *number2 = new int();
	cout << "Did't init, new int equal == "<<*number1 << endl;
	//init, new int() equal == 随机值
	cout << "init, new int() equal == " << *number2 << endl;
	//init, new int() equal == 0
	cout << "the size of new int :" << sizeof(*number1) << endl;
	//the size of new int : 4
	cout << "the size of new int() :" << sizeof(*number2) << endl;
	//the size of new int : 4
	system("pause");
}