5 函数重载（Overroad）
函数重载概念
1 函数重载概念
函数重载(Function Overload)
    用同一个函数名定义不同的函数
    当函数名和不同的参数搭配时函数的含义不同

2 函数重载的判断标准
/*
函数重载至少满足下面的一个条件：
    参数个数不同
    参数类型不同
    参数顺序不同
*/
3 函数返回值不是函数重载的判断标准
实验1：调用情况分析；实验2：判断标准
//两个难点：重载函数和默认函数参数混搭 重载函数和函数指针
/*
int func(int x)
{
    return x;
}

int func(int a, int b)
{
    return a + b;
}

int func(const char* s)
{
    return strlen(s);
}

int main()
{
    int c = 0;

    c = func(1);

    printf("c = %d\n", c);

    c = func(1, 2);

    printf("c = %d\n", c);

    c = func("12345");

    printf("c = %d\n", c);

    printf("Press enter to continue ...");
    getchar();    
    return 0;
}
*/
函数重载的调用准则
/*
编译器调用重载函数的准则
    将所有同名函数作为候选者
    尝试寻找可行的候选函数
    精确匹配实参
    通过默认参数能够匹配实参
    通过默认类型转换匹配实参
    匹配失败
    最终寻找到的可行候选函数不唯一，则出现二义性，编译失败。
    无法匹配所有候选者，函数未定义，编译失败。
*/

/*
函数重载的注意事项
    重载函数在本质上是相互独立的不同函数（静态链编）
    重载函数的函数类型是不同的
    函数返回值不能作为函数重载的依据
函数重载是由函数名和参数列表决定的。
*/
函数重载是发生在一个类中里面
函数重载遇上函数默认参数
//当函数默认参数遇上函数重载会发生什么
/*
int func(int a, int b, int c = 0)
{
    return a * b * c;
}

int func(int a, int b)
{
    return a + b;
}

//1个参数的允许吗
int func(int a)
{
    return a + b;
}


int main()
{
    int c = 0;

    c = func(1, 2); // 存在二义性，调用失败，编译不能通过

    printf("c = %d\n", c);

    printf("Press enter to continue ...");
    getchar();    
    return 0;
}
*/

函数重载和函数指针结合
/*
函数重载与函数指针
    当使用重载函数名对函数指针进行赋值时
    根据重载规则挑选与函数指针参数列表一致的候选者
    严格匹配候选者的函数类型与函数指针的函数类型
*/
/*
int func(int x) // int(int a)
{
    return x;
}

int func(int a, int b)
{
    return a + b;
}

int func(const char* s)
{
    return strlen(s);
}

typedef int(*PFUNC)(int a); // int(int a)

int main()
{
    int c = 0;
    PFUNC p = func;

    c = p(1);

    printf("c = %d\n", c);

    printf("Press enter to continue ...");
    getchar();    
    return 0;
}
*/
函数重载、重写、重定义
后续课程。
8附录
附录1：C++语言对C语言扩充和增强的几点具体体现
