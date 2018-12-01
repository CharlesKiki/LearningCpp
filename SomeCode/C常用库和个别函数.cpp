<math.h>//数学库
const int PI = 4 * atan (1);
//注意这个方式atan()得到了精度保证的Pi值
cc rect_pol.c -lm
//注意这个命令，在UNIX系统中存在一个附加参数可以对链接器进行指定操作
//对c文件的编译是 cc
gcc rect_pol.c -lm
//Linux系统中 对c文件的编译是gcc
<stdlib.h>//通用工具库
// byebye.c -- atexit( )示例程序
#include <stdio.h>
#include <stdlib.h>  //注意这两个库的不同，一个是标准库一个是标准输出
 
void sign_off (void);
//函数声明
void too_bad (void);
 //函数声明
int main (void)
{
    int n;
 
    atexit (sign_off); // 注册sign_off( )函数
    //注意这个函数的执行时间是在main()之后
    //这个函数和析构函数存在着调用的关系，功能类似
    //但是概念上exit()会释放一些静态的数据
    //但是栈更多是动态的概念？这点需要证实
    puts ("Enter an integer: ");
    if (scanf ("%d", &n) != 1)
    {
        puts ("That's no integer!");
        atexit (too_bad);
        exit (EXIT_FAILURE);
        //注意一些符号常量，类似宏定义，它们通常存在于头文件中
        //#define EXIT_FAILURE 1
        //对应的存在一个符号常量是成功执行 EXIT_SUCCESS
        //这些符号常量通常可以用来当作是是否正常运行
    }
    printf ("%d is %s.\n", n, (n % 2 == 0) ? "even" : "odd");
 
    return 0;
}
 
void sign_off(void)
{
    puts ("Thus terminates another magnificent program from");
    puts ("SeeSaw Software!");
}
 
void too_bad (void)
{
    puts ("SeeSaw Software extends its heartfelt condolences");
    puts ("to you upon the failure of your program");
}
//return()返回上层调用
//return()属于一种正常退出 return, exit, _exit, _Exit, pthreade_exit
//异常退出 abort, SIGNAL, 线程响应取消
//在main()中exit()等价于return()
//exit()的意义在于对象的声明周期结束以前程序媛可以对其进行操作

// qsorter.c -- 使用qsort()对一组数字排序
#include <stdio.h>
#include <stdlib.h>
 
#define NUM 40
 
void fillarray (double ar[], int n);
void showarray (const double ar[], int n);
int mycomp (const void * p1, const void * p2);
 
int main (void)
{
    double vals[NUM];
    fillarray (vals, NUM);
    puts ("Random list: ");
    showarray (vals, NUM);
    qsort (vals, NUM, sizeof(double), mycomp);
    //注意这个函数的四个参数
    //数组头部指针，项目数量，每个数组元素大小，一个用于排序的数组
    puts ("Sorted list: ");
    showarray (vals, NUM);
 
    return 0;
}
 
void fillarray (double ar[], int n)
{
    int index;
 
    for (index = 0; index < n; index++)
        ar[index] = (double)rand() / ((double)rand() + 0.1);
}
 
void showarray (const double ar[], int n)
{
    int index;
 
    for (index = 0; index < n; index++)
    {
        printf ("%9.4f ", ar[index]);
        if (index % 6 == 5)
            putchar ('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}
 
int mycomp (const void * p1, const void * p2)
{
    const double * a1 = (const double *)p1;
    const double * a2 = (const double *)p2;
 
    return *a1 - *a2;
}