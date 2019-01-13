#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x, z;
	char y;
	/*
		作用：输出多少个字符scanf接收了
		格式化分别为:字符格式 整型格式 整型格式
		字符格式接收字符存入int 正确
		整型格式接收字符存入char 正确
		整型格式接收字符存入int 错误
			结论：格式化和输入必须一一对应
			而变量会对内容重新解释。
	*/
	printf("%d", scanf("%c,%d,%d", &x, &y, &z));
	printf("%d", x);
	printf("%d", y);
	/*
		commit:scanf返回值是成功接收的变量个数
		1.字符类型无法转换为十进制类型。 输入和格式化错误
		2.键盘的字符只能用%c格式化 对应 
		3.键盘的数字只能用%d格式化 对应
		4.字符char占用1byte，int占用2byte
			结论：格式化值和变量类型不对应
			输出的值就是奇怪的。
	*/
	system("pause");
	return 0;
}