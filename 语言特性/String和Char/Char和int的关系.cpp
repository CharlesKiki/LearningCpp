#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
	char ch = 74;
	cout << "赋值74的char类型输出为：" << ch << endl;
	char ch2 = 'a';
	cout << "赋值'a'的char类型输出为：" << ch2 << endl;
	/*
		结果：赋值74的char类型输出为：J
		结论:char类型的值是十进制数字，用char类型解释后映射成为字符，在内存中以二进制存储。
	*/
	system("pause");
	return 0;
}
/*
	commit：
			在对字符型数据进行相加减运算的时候，
			系统会首先将char型数据以隐形的方式转化为int型数据再进行相加减运算。
			因此，由字符型数据在内存的存储方式来看，
			字符型数据在做数字运算时实际上是对字符本身对应的ASCII码进行相应的数值运算。
			char a = 'a';这是用字符常量直接赋值，
			编译器会将'a'解释成a的ASCII码97，然后存入变量a中，
			然后输出的时候又将整数转化为字符格式输出.
*/