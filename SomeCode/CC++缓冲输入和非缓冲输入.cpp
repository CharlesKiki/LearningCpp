#include "stdio.h"
int main(void)
{
    int d;
    char ch;
    printf("Input a character:");
    ch=getchar();
    //注意这个函数是缓冲区函数，直到Enter之后才会将缓存区内容推入程序
    //关于它的工作方式，它是一个一个字符返回值给程序的
    //如果出错则会返回-1
    printf("\nYou input a '%c'\n", ch);
    ch = getche();
    //这个函数带有回显功能，作用在控制台
    printf("\nYou input a '%c'\n", ch);
    ch=getch();
    //注意这个函数，它不会等待用户的Enter，而是字节读取内容到程序中
    printf("\nYou input a '%c'\n", ch);
    
    while((ch=getchar())!='\n')
    {
        putchar(ch);
        //这是一个C函数，输出一个char定义好的常量
    }
    getchar();
    return 0;
}

void main() //注意这个函数的定义在C++和C都是错误的 
{

}
int main( void )  //z正确方式 
{

}
 int main( int argc, char *argv[] )   //正确方式
 {

 }
 //注意一个概念程序的激活者大多是操作系统，而操作系统需要一个返回值来确认状态。
