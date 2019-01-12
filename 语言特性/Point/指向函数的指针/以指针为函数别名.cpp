/*
	功能：
*/
#include<stdio.h>
#include<stdlib.h>
/*
	函数功能：
			接受两个int类型参数，返回int类型值
			从两个参数中返回更大的那个
*/
int max(int x,int y)
{ return(x>y?x:y); }
/*
	测试用例：
			用来测试函数指针
*/
int main()
{
	/*
		commit：函数指针以返回值和配合*运算符别名
		返回类型 指针 参数类型以及数量
		小技巧，函数指针的本质还是指针，这意味着typedef关键字
		可以直接使用指针名。
	*/
	int (*ptr)(int, int);
	int a,b,c;
	/*
		commit:声明了函数指针之后还需要和对应形式的函数赋值
	*/
	ptr=max;
	scanf("%d%d",&a,&b);
	/*
		Commit：函数指针调用形式为(*point)(parameter)
	*/
	c=(*ptr)(a,b);
	printf("a=%d,b=%d,max=%d",a,b,c);
	system("PAUSE"); 
	return 0;

}