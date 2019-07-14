2 默认参数
/*1
C++中可以在函数声明时为参数提供一个默认值，
    当函数调用时没有指定这个参数的值，编译器会自动用默认值代替
*/
void myPrint(int x = 3)
{
    printf("x:%d", x);
}
/*2
函数默认参数的规则
    只有参数列表后面部分的参数才可以提供默认参数值
    一旦在一个函数调用中开始使用默认参数值，那么这个参数后的所有参数都必须使用默认参数值
*/

//默认参数
void printAB(int x = 3)
{
    printf("x:%d\n", x);
}

//在默认参数规则 ，如果默认参数出现，那么右边的都必须有默认参数
void printABC(int a, int b, int x = 3, int y=4, int z = 5)
{
    printf("x:%d\n", x);
}
int main62(int argc, char *argv[])
{
    printAB(2);
    printAB();
    system("pause");
    return 0;
}
3 函数占位参数
/*
函数占位参数  
占位参数只有参数类型声明，而没有参数名声明
一般情况下，在函数体内部无法使用占位参数
*/

int func(int a, int b, int )
{
    return a + b;
}

int main01()
{
    //func(1, 2); //可以吗？
    printf("func(1, 2, 3) = %d\n", func(1, 2, 3));

    getchar();    
    return 0;
}

4 默认参数和占位参数
/*
可以将占位参数与默认参数结合起来使用
    意义
    为以后程序的扩展留下线索  
    兼容C语言程序中可能出现的不规范写法
    */
//C++可以声明占位符参数，占位符参数一般用于程序扩展和对C代码的兼容
int func2(int a, int b, int = 0)
{
    return a + b;
}
void main()
{
    //如果默认参数和占位参数在一起，都能调用起来
    func2(1, 2);
    func2(1, 2, 3);
    system("pause");
}
结论：//如果默认参数和占位参数在一起，都能调用起来