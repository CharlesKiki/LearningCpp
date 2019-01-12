#include <stdio.h>
#include <string.h>
#define NumTest 1024  //注意，定义全局变量不需要分号 不需要等号
#define StrTest "This is a test"
int main(void)
{
	char NameTest[40];
	scanf("%s",NameTest);
	printf("ENDENDENDENDENDEND.\n");
	printf("%s.\n",StrTest);
	return 0;
}

int main2(void)
{
	int num;
	num = 1;
	printf("%d",num);
	return 0;
}

int main3(void)	
{
	int Num1,Num2=0;  //注意，这种赋值方式很差
	printf("Please enter a number \n");
	scanf("%d",&Num1);
	Num2=2 * Num1;
	printf("%d %d \n",Num1,Num2);
	printf("%d  \n",2 * Num1);  //注意这的参数形式
	rintf("%d %o %x \n",2 * Num1,Num1,Num2);   //十进制 八进制 十六进制
	Fun();
}

void Fun()
{
	char Test;
	Test = 'T'; //视为存储T 字符常量
	Test = T;   //错误，视为一个变量
	Test = "T";  //错误，视为 ”T“ 为字符串
	printf("ENDENDENDENDENDEND.\n");
}

