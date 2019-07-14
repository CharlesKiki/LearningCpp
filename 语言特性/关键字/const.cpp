

//1 const基础知识（用法、含义、好处）

int main()
{
const int a;
int const b;

const int *c;
int * const d;
const int * const e ;

return 0;
}

Int func1(const )
//初级理解：const是定义常量==》const意味着只读
//含义：
//第一个第二个意思一样 代表一个常整形数
//第三个 c是一个指向常整形数的指针(所指向的内存数据不能被修改，但是本身可以修改)
//第四个 d 常指针（指针变量不能被修改，但是它所指向内存空间可以被修改）
//第五个 e一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）
//Const好处
//合理的利用const，
//1指针做函数参数，可以有效的提高代码可读性，减少bug；
//2清楚的分清参数的输入和输出特性
int setTeacher_err( const Teacher *p)
//Const修改形参的时候，在利用形参不能修改指针所向的内存空间
//2 C中“冒牌货”

int main()
{
    const int a = 10;
    int *p = (int*)&a;
    printf("a===>%d\n", a);
    *p = 11;
    printf("a===>%d\n", a);

    printf("Hello......\n");
    return 0;
}
/* 解释：
C++编译器对const常量的处理
当碰见常量声明时，在符号表中放入常量 =问题：那有如何解释取地址
编译过程中若发现使用常量则直接以符号表中的值替换
编译过程中若发现对const使用了extern或者&操作符，则给对应的常量分配存储空间（兼容C）
？联想： int &a = 1(err) & const int &a = 10(ok)?  
C++中const符号表原理图 */

/* 
注意：
C++编译器虽然可能为const常量分配空间，但不会使用其存储空间中的值。
结论：
C语言中的const变量
C语言中const变量是只读变量，有自己的存储空间
C++中的const常量
可能分配存储空间,也可能不分配存储空间  
当const常量为全局，并且需要在其它文件中使用
当使用&操作符取const常量的地址 */

//3 const和#define相同之处
//练习 解释为什么
//#define N 10
int main()
{
    const int a = 1;
    const int b = 2;
    int array[a + b ] = {0};
    int i = 0;
    
    for(i=0; i<(a+b); i++)
    {
        printf("array[%d] = %d\n", i, array[i]);
    }
    
    
    getchar();
    
    return 0;
}
/* C++中的const修饰的，是一个真正的常量，而不是C中变量（只读）。在const修饰的常量编译期间，就已经确定下来了。
4 const和#define的区别    
对比加深
C++中的const常量类似于宏定义
const int c = 5; ≈ #define c 5
C++中的const常量与宏定义不同
const常量是由编译器处理的，提供类型检查和作用域检查
宏定义由预处理器处理，单纯的文本替换 */
//在func1定义a，在func2中能使用吗？
//在func1中定义的b，在func2中能使用吗？
//练习
void fun1()
{
    #define a 10
    const int b = 20;
    //#undef a  # undef
}

void fun2()
{
    printf("a = %d\n", a);
    //printf("b = %d\n", b);
}

int main()
{
    fun1();
    fun2();
    return 0;
}


/* 5 结论
C语言中的const变量
C语言中const变量是只读变量，有自己的存储空间
C++中的const常量
可能分配存储空间,也可能不分配存储空间  
当const常量为全局，并且需要在其它文件中使用，会分配存储空间
当使用&操作符，取const常量的地址时，会分配存储空间
当const int &a = 10; const修饰引用时，也会分配存储空间 */