//register关键字 请求编译器让变量a直接放在寄存器里面，速度快
//在c语言中 register修饰的变量 不能取地址，但是在c++里面做了内容

/*
//1
register关键字的变化
register关键字请求“编译器”将局部变量存储于寄存器中
C语言中无法取得register变量地址
在C++中依然支持register关键字
C++编译器有自己的优化方式，不使用register也可能做优化
C++中可以取得register变量的地址

//2
C++编译器发现程序中需要取register变量的地址时，register对变量的声明变得无效。

//3
早期C语言编译器不会对代码进行优化，因此register变量是一个很好的补充。

*/
int main22()
{
    register int a = 0; 

	printf("&a = %x\n", &a);

	system("pause");
	return 0;
}