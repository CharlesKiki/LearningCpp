/* 6引用专题讲座
1引用（普通引用）
变量名回顾
变量名实质上是一段连续存储空间的别名，是一个标号(门牌号)
程序中通过变量来申请并命名内存空间   
通过变量的名字可以使用存储空间
问题1：对一段连续的内存空间只能取一个别名吗？
1 引用概念
a)在C++中新增加了引用的概念
b)引用可以看作一个已定义变量的别名
c)引用的语法：Type& name = var;
d） 引用做函数参数那？（引用作为函数参数声明时不进行初始化） */
void main01()
{
    int a = 10; //c编译器分配4个字节内存。。。a内存空间的别名
    int &b = a;  //b就是a的别名。。。
    a =11; //直接赋值
    {
        int *p = &a;
        *p = 12;
        printf("a %d \n",a);
    }
    b  = 14;
    printf("a:%d b:%d", a, b);
    system("pause");
}
/* 2 引用是C++的概念   
属于C++编译器对C的扩展
问题：C中可以编译通过吗？ */
int main()
{
    int a = 0;
    int &b = a; //int * const b = &a
     b = 11;  //*b = 11;

    return 0;
}
/* 结论：请不要用C的语法考虑 b=11
3 引用做函数参数
普通引用在声明时必须用其它的变量进行初始化，
引用作为函数参数声明时不进行初始化 */
//05复杂数据类型 的引用
struct Teacher
{
    char name[64];
    int age ;
};

void printfT(Teacher *pT)
{
    cout<<pT->age<<endl;
}

//pT是t1的别名 ,相当于修改了t1
void printfT2(Teacher &pT)
{
    //cout<<pT.age<<endl;
    pT.age = 33;
}

//pT和t1的是两个不同的变量
void printfT3(Teacher pT)
{
    cout<<pT.age<<endl;
    pT.age = 45; //只会修改pT变量 ,不会修改t1变量
}
void main()
{
    Teacher t1;
    t1.age = 35;

    printfT(&t1);

    printfT2(t1); //pT是t1的别名
    printf("t1.age:%d \n", t1.age); //33

    printfT3(t1) ;// pT是形参 ,t1 copy一份数据 给pT     //---> pT = t1
    printf("t1.age:%d \n", t1.age); //35
    
    cout<<"hello..."<<endl;    
    system("pause");
    return ;
}

/* 4 引用的意义
1）引用作为其它变量的别名而存在，因此在一些场合可以代替指针
2）引用相对于指针来说具有更好的可读性和实用性


5 引用本质思考
思考1：C++编译器背后做了什么工作？ */
int main()
{
       int a = 10;
    int &b = a;
    //b是a的别名，请问c++编译器后面做了什么工作？
    b = 11;
    cout<<"b--->"<<a<<endl;
    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("&a:%d\n", &a);
    printf("&b:%d\n", &b);  //请思考：对同一内存空间可以取好几个名字吗？
    system("pause");
    return 0;
}
/* 单独定义的引用时，必须初始化；说明很像一个常量
思考2：普通引用有自己的空间吗？ */
struct Teacer {
    int &a;
    int &b;
};
int main()
{
    printf("sizeof(Teacher) %d\n", sizeof(Teacer));
    system("pause");
    return 0;
}
//引用是一个有地址，引用是常量。。。。。
char *const p

/* 6 引用的本质
1）引用在C++中的内部实现是一个常指针
Type& name Type* const name
2）C++编译器在编译过程中使用常指针作为引用的内部实现，因此引用所占用的空间大小与指针相同。
3）从使用的角度，引用会让人误会其只是一个别名，没有自己的存储空间。这是C++为了实用性而做出的细节隐藏 */

Int main()
{
int x  = 10;
        func(x);
}
4）请仔细对比间接赋值成立的三个条件
1定义两个变量 （一个实参一个形参）
2建立关联 实参取地址传给形参
3*p形参去间接的修改实参的值
7引用结论
1）引用在实现上，只不过是把：间接赋值成立的三个条件的后两步和二为一
//当实参传给形参引用的时候，只不过是c++编译器帮我们程序员手工取了一个实参地址，传给了形参引用（常量指针）
2）当我们使用引用语法的时，我们不去关心编译器引用是怎么做的
当我们分析奇怪的语法现象的时，我们才去考虑c++编译器是怎么做的
8函数返回值是引用(引用当左值)
C++引用使用时的难点：
当函数返回值为引用时
若返回栈变量
不能成为其它引用的初始值
不能作为左值使用
若返回静态变量或全局变量
可以成为其他引用的初始值
即可作为右值使用，也可作为左值使用
    C++链式编程中，经常用到引用，运算符重载专题

返回值是基础类型，当引用
int getAA1()
{
    int a;
    a = 10;
    return a;
}

//基础类型a返回的时候，也会有一个副本
int& getAA2()
{
    int a;
    a = 10;
    return a;
}

int* getAA3()
{
    int a;
    a = 10;
    return &a;
}

返回值是static变量，当引用
//static修饰变量的时候，变量是一个状态变量
int j()
{
    static int a = 10;
    a ++;
    printf("a:%d \n", a);
    return a;

}

int& j1()
{
    static int a = 10;
    a ++;
    printf("a:%d \n", a);
    return a;
}

int *j2()
{
    static int a = 10;
    a ++;
    printf("a:%d \n", a);
    return &a;
}

void main22()
{
    // j()的运算结果是一个数值，没有内存地址，不能当左值。。。。。
    //11 = 100;
    //*(a>b?&a:&b) = 111;
    //当被调用的函数当左值的时候，必须返回一个引用。。。。。
    j1() = 100; //编译器帮我们打造了环境
    j1();
    *(j2()) = 200; //相当于我们程序员手工的打造 做左值的条件
    j2();
    system("pause");
}

返回值是形参，当引用

int  g1(int *p)
{
    *p = 100;
    return *p;
}

int&  g2(int *p) //
{
    *p = 100;
    return *p;
}



//当我们使用引用语法的时候 ，我们不去关心编译器引用是怎么做的
//当我们分析乱码这种现象的时候，我们才去考虑c++编译器是怎么做的。。。。
void main23()
{
    int a1 = 10;
    a1 = g2(&a1);

    int &a2 = g2(&a1); //用引用去接受函数的返回值，是不是乱码，关键是看返回的内存空间是不是被编译器回收了。。。。
    printf("a1:%d \n", a1);
    printf("a2:%d \n", a2);

    system("pause");
}


返回值非基础类型
struct Teachar
{
    char name[64];
    int age;
};
//如果返回引用不是基础类型，是一个类，那么情况非常赋值。。涉及到copy构造函数和=操作重载，抛砖。。。。
struct Teachar
{
    char name[64];
    int age;
};
//如果返回引用不是基础类型，是一个类，那么情况非常赋值。。涉及到copy构造函数和=操作重载，抛砖。。。。

struct Teachar & OpTeacher(struct Teachar &t1)
{
    
}
9指针引用
#include "iostream"
using namespace std;

struct Teacher
{
    char name[64];
    int age;
};

int getTe(Teacher **myp )
{
    Teacher *p = (Teacher *)malloc(sizeof(Teacher));
    
    if (p ==NULL)
    {
        return -1;
    }
    memset(p, 0, sizeof(Teacher));
    p->age = 33;

    *myp  = p; //
    return 0;
}

//指针的引用而已
int getTe2(Teacher*  &myp)
{
    myp = (Teacher *)malloc(sizeof(Teacher));
    myp->age = 34;

    return 0;
}

void main333()
{
    Teacher *p = NULL;
    //getTe(&p);
    getTe2(p);

    printf("age:%d \n", p->age);
    system("pause");
}
2常引用
下面开始进入const引用难点
1 使用变量初始化const引用
思考cost int &a = b PK const int &a = 10;
？？？？问题：const引用，
在C++中可以声明const引用
const Type& name = var；
const引用让变量拥有只读属性
案例1：
int main()
{
    int a = 10;
    const int &b = a;

    //int *p = (int *)&b;
    b = 11; //err
    //*p = 11; //只能用指针来改变了

    cout<<"b--->"<<a<<endl;
    printf("a:%d\n", a);
    printf("b:%d\n", b);
    printf("&a:%d\n", &a);
    printf("&b:%d\n", &b);
    system("pause");
    return 0;
}
案例2：
void main41()
{
    int a = 10;

    const int &b = a; //const引用 使用变量a初始化
    a = 11;
    //b = 12; //通过引用修改a,对不起修改不了
    system("pause");
}


struct Teacher1
{
    char name[64];
    int age;
};

void printTe2(const Teacher1 *const pt)
{

}

//const引用让变量(所指内存空间)拥有只读属性
void printTe(const Teacher1 &t)
{
    //t.age  = 11;
}
void main42()
{
    Teacher1 t1;
    t1.age = 33;
    printTe(t1);
    system("pause");
}
2使用字面量常量初始化const引用
思考：
1、用变量对const引用初始化，const引用分配内存空间了吗？
2、用常量对const引用初始化，const引用分配内存空间了吗？
void main()
{
    const int b = 10;
    printf("b:%d", &b);

    //int &a1 = 19; 如果不加const编译失败
    const int &a = 19;
    printf("&a:%d \n", &a);

    system("pause");
}

3 综合案例
void main()
{
    //普通引用
    int a = 10;
    int &b = a;
    //常量引用 ：让变量引用只读属性
    const int &c = a;  

    //常量引用初始化 分为两种
    //1 用变量 初始化 常量引用
    {
        int x = 20;
        const int& y = x;
        printf("y:%d \n", y);
    }

    //2 用常量 初始化 常量引用
    {
        //int &m = 10; //引用是内存空间的别名 字面量10没有内存空间 没有方法做引用
        const int &m = 10;
    }
    cout<<"hello..."<<endl;
    system("pause");
    return ;
}
3 const引用结论  
1）Const & int e  相当于 const int * const e
2）普通引用 相当于 int *const e1
3）当使用常量（字面量）对const引用进行初始化时，C++编译器会为常量值分配空间，并将引用名作为这段空间的别名
4）使用字面量对const引用初始化后，将生成一个只读变量
4const修饰类
    后续课程介绍
5综合练习

int& j()
{
    static int a = 0;
    return a;
}

int& g()
{
    int a = 0;
    return a;
}

int main()
{
    int a = g();
    int& b = g();
    j() = 10;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("f() = %d\n", f());
    system("pause");
    return 0;
}