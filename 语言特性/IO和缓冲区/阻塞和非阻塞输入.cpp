#include <string> 
#include <iostream>
using namespace std;

int main()
{
	char a;
	int b;
	float c;
	string str;
	/*
		commit:Cin测试，当连续对多个变量输入时，Cin会排除回车和空格，直到缓冲区非空--阻塞式IO。

	*/
	cin >> a >> b >> c >> str;
	cout << a << " " << b << " " << c << " " << str << endl;
	/*
		commit:当给str输入byte流时，实际上回车和空格是实际存在的字符。
		getline()是C++的方法，不阻塞，对回车符敏感。
	*/
	string test;
	getline(cin, test);//不阻塞
	cout << "test:" << test << endl;
	cout << "the length of test is" + test << endl;
	system("pause");
	return 0;
}