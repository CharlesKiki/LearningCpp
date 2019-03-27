/*
    程序功能：getchar() getche() getch() putchar() 的区别
*/
#include "stdio.h"
int main(void)
{
    char ch;                        //字符变量
    printf("Input a character:");   //获取字符
    ch=getchar();
    printf("\nYou input a '%c'\n", ch);
    ch = getche();                  //带有回显功能，作用在控制台
    printf("\nYou input a '%c'\n", ch);
    ch=getch();                     //它不等待用户Enter，而是字节读取内容到程序中
    printf("\nYou input a '%c'\n", ch);
    

    while((ch=getchar())!='\n')
    {
        putchar(ch);                //这是一个C函数，输出一个char定义好的常量
    }
    getchar();
    return 0;
}
