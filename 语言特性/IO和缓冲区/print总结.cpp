#include <stdio.h>
#include <string.h>
#define NumTest 1024  
#define StrTest "This is a test"

int main(void)
{
	char NameTest[40];		
	scanf("%s",NameTest);
	printf("What you just enter is %s.\n",NameTest);  
	printf("ENDENDENDENDENDEND.\n");
	printf("The global constant define is %s.\n",StrTest);         //打印常量
	return 0;
}
/*
	实验结果：
	What you just enter is test.
	ENDENDENDENDENDEND.
	The global constant define is This is a test.

	结论：度打印一个数组不需要声明它的长度，它会自动的输出
*/

/*
	功能：打印一个整形变量
*/
int main2(void)
{
	int num;
	num = 1;
	printf("%d",num);
	return 0;
}

/*
	功能：格式化输出
*/
int main3(void)	
{
	int Num1,Num2=0;  							  //注意，这种赋值方式很差
	printf("Please enter a number \n");
	scanf("%d",&Num1);
	Num2=2 * Num1;
	printf("The number1 is  %d ，number2 is  %d \n",Num1,Num2);
	printf("%d  \n",2 * Num1);  				  //注意这的参数形式
	printf("%d %o %x \n",2 * Num1,Num1,Num2);     //十进制 八进制 十六进制
	//Fun();
	return 0;
}
/*
	注意：char类型不能存储一个""的字符串
*/
/*
void Fun()
{
	char Test;
	Test = 'T'; 		//视为存储T 字符常量
	Test = T;   		//错误，视为一个变量
	Test = "T";  		//错误，视为 ”T“ 为字符串
	printf("ENDENDENDENDENDEND.\n");
}
*/
