#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	函数功能：对变量操作的几种方法
	注释：
		方法1：直接赋值
		方法2：间接赋值
		方法3：对内存空间能不能再取别名
*/
void main()
{
	int a ;
	int b; 
	char *    p ;
	//p = 0xaa11
	//1 直接赋值  //cpu里面执行
	a = 10; 

	printf("&a: %d\n", &a);

	//2.间接赋值，直接通过内存。这没有变量的声明过程。
	 *((int*)1245024) = 200;

	 printf("a: %d\n", a);


	/*
		Commit：这是一个花括号体，内部变量只在此作用域内发生作用，超出范围就会被销毁
	*/
	 {
		p = 1245024;  // 间接赋值 通过指针

		*p = 300;
	 }

	 //3.对内存空间能不能再取别名，C++ 引用
	system("pause");
	return ;
}

void sub1()
{

}