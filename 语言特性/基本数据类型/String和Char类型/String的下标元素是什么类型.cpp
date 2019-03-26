#include <iostream> 
#include <string>
#include <stdlib.h>
using namespace std;
int main()
{
	/*
		commit:string 使用小技巧：对某个下标取地址可以截取下标之后的字符输出
	*/
	string s = "hello world";
	cout << "下标第三个元素是：" << s[3] << endl;
	cout << "对第三个下标取地址为：" << &s[3] << endl;
	//检查数据类型
	if (typeid(s[3]) == typeid(char))
	{
		cout << "String下标元素是char类型。";
	}
	if (typeid(s[3]) == typeid(int))
	{
		cout << "String下标元素是int类型。";
	}
	if (typeid(s[3]) == typeid(string))
	{
		cout << "String下标元素是string类型。";
	}
	system("pause");
	return 0;
}

