#include   <stdio.h> // 参数可以距离多个空格 第一个代码块前二十个数字和
//old-style parameter declarations in prototyped function definition| 声明函数时要加入分号
void squares(void);
int main (void)  //对main（）函数的声明不需要使用分号
{
    int count , sum ;
    count=0;
    sum=0;
    while(count++<20)  //小于号和参数符号一样
        sum = sum +count;
        printf("sun = %d",sum);



}
//符号 ++
//现在尝试加入另外一个函数
void squares(void)
{
    int num =1;
    while (num<21);
    {
        printf("%4d %6d\n",num,num *num);
        num = num +1;
    }
    return 0;
}
