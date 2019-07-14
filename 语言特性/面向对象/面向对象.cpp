
2、类和对象
1前言
C++学习技术路线及目标
    研究C++编译器管理类和对象的方法 ===》避免死角
        c++编译器对类对象的生命周期管理，对象创建、使用、销毁
        c++面向对象模型初探
        c++面向对象多态原理探究
        操作符重载
C++基础课程学习完毕以后，有没有一个标准，来判断自己有没有入门。
        面向抽象类（接口）编程

2类和对象
2.1 基本概念
1）类、对象、成员变量、成员函数
2）面向对象三大概念
封装、继承、多态
3）编程实践
    类的定义和对象的定义，对象的使用
    求圆形的面积
    定义Teacher类，打印Teacher的信息（把类的声明和类的实现分开）
2.2类的封装
1）封装（Encapsulation）
A）封装，是面向对象程序设计最基本的特性。把数据（属性）和函数（操作）合成一个整体，这在计算机世界中是用类与对象实现的。
B）封装，把客观事物封装成抽象的类，并且类可以把自己的数据和方法只让可信的类或者对象操作，对不可信的进行信息隐藏。
    备注：有2层含义（把属性和方法进行封装 对属性和方法进行访问控制）
    C++中类的封装
成员变量，C++中用于表示类属性的变量
成员函数，C++中用于表示类行为的函数
2）类成员的访问控制
在C++中可以给成员变量和成员函数定义访问级别
Public修饰成员变量和成员函数可以在类的内部和类的外部被访问
Private修饰成员变量和成员函数只能在类的内部被访问
//类是把属性和方法封装 同时对信息进行访问控制
//类的内部，类的外部
//我们抽象了一个类，用类去定义对象
//类是一个数据类型，类是抽象的
//对象是一个具体的变量。。占用内存空间。
class Circle
{
public:
    double r;
    double s;
public:
    double getR()  
    {
        a++;
        return r;
    }
    void setR(double val)
    {
        r = val;
    }
public:
    double getS() //增加功能时，是在修改类, 修改类中的属性或者是方法
    {
         s = 3.14f*r*r;
         return s;
    }
//private:
    int a;
};

3）struct和class关键字区别
在用struct定义类时，所有成员的默认属性为public
在用class定义类时，所有成员的默认属性为private
2.3 C++面向对象程序设计举例
目标：面向过程向面向对象思想转变
    初学者要仔细体会类和对象之间的关系，并通过适当练习巩固和提高！
案例1    设计立方体类(cube)，求出立方体的面积和体积
        求两个立方体，是否相等（全局函数和成员函数）

案例2    设计一个圆形类（AdvCircle），和一个点类（Point），计算点在圆内部还是圆外
        即：求点和圆的关系（圆内和圆外）

案例3    对于第二个案例，类的声明和类的实现分开

2.4 作业
作业1：编写C++程序完成以下功能：
1）定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；
2）定义一个圆形类，其属性包括圆心和半径；
3）创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果。

作业2：设计并测试一个名为Rectangle的矩形类，其属性为矩形的左下角与右上角两个点的坐标，根据坐标能计算出矩形的面积

作业3：定义一个Tree类，有成员ages（树龄），成员函数grow（int years）对ages加上years，age（）显示tree对象的ages的值。
    
3对象的构造和析构
前言
创建一个对象时，常常需要作某些初始化的工作，例如对数据成员赋初值。注意，类的数据成员是不能在声明类时初始化的。
为了解决这个问题，C++编译器提供了构造函数(constructor)来处理对象的初始化。构造函数是一种特殊的成员函数，与其他成员函数不同，不需要用户来调用它，而是在建立对象时自动执行。
3.1构造和析构函数
1构造函数和析构函数的概念
有关构造函数
1构造函数定义及调用
1）C++中的类可以定义与类名相同的特殊成员函数，这种与类名相同的成员函数叫做构造函数；
2）构造函数在定义时可以有参数；
3）没有任何返回类型的声明。
2构造函数的调用
自动调用：一般情况下C++编译器会自动调用构造函数
手动调用：在一些情况下则需要手工调用构造函数

有关析构函数
3）析构函数定义及调用
    1）C++中的类可以定义一个特殊的成员函数清理对象，这个特殊的成员函数叫做析构函数
语法：~ClassName()
2）析构函数没有参数也没有任何返回类型的声明
3）析构函数在对象销毁时自动被调用
4）析构函数调用机制
    C++编译器自动调用
代码演示：dm01_构造函数的基础.cpp
2 C++编译器构造析构方案 PK 对象显示初始化方案
设计构造函数和析构函数的原因
面向对象的思想是从生活中来，手机、车出厂时，是一样的。
生活中存在的对象都是被初始化后才上市的；初始状态是对象普遍存在的一个状态的
普通方案：
为每个类都提供一个public的initialize函数；
对象创建后立即调用initialize函数进行初始化。
优缺点分析
1）initialize只是一个普通的函数，必须显示的调用
2）一旦由于失误的原因，对象没有初始化，那么结果将是不确定的
没有初始化的对象，其内部成员变量的值是不定的
3）不能完全解决问题
//为什么对象需要初始化 有什么样的初始化方案
#include "iostream"
using namespace std;

/*
思考为什么需要初始化
    面向对象思想来自生活，手机、车、电子产品，出厂时有初始化
    怎么样进行初始化？

方案1：显示调用方法
缺点：易忘、麻烦；显示调用init，不能完全解决问题
*/
class Test21
{
public:
    int m;
    int getM() const { return m; }
    void setM(int val) { m = val; }

    int n;
    int getN() const { return n; }
    void setN(int val) { n = val; }

public:
    int init(int m,int n)
    {
        this->m = m;
        this->n = n;
        return 0;
    }
protected:
private:
};

int main()
{
    int rv =0;
    Test21 t1;  //无参构造函数的调用方法
    Test21 t2;

    //t1.init(100, 200);
    //t2.init(300, 400);
    cout<<t1.getM()<<" "<<t1.getN()<<endl;
    cout<<t2.getM()<<" "<<t2.getN()<<endl;

    //定义对象数组时，没有机会进行显示初始化
    Test21 arr[3];
    //Test arr_2[3] = {Test(1,3), Test(), Test()};

    system("pause");
    return rv;
}
3.2构造函数的分类及调用
C++编译器给程序员提供的对象初始化方案，高端大气上档次。
//有参数构造函数的三种调用方法
class Test
{
private:
    int a;
    int b;

public:
    
    //无参数构造函数
    Test()
    {
        ;
    }
    
    //带参数的构造函数
    Test(int a, int b)
    {
        ;
    }
    //赋值构造函数
    Test(const Test &obj)
    {
        ;
    }

public:
    void init(int _a, int _b)
    {
        a = _a;
        b = _b;
    }
};
1无参数构造函数
    调用方法： Test t1, t2;
2有参构造函数
有参构造函数的三种调用方法
//有参数构造函数的三种调用方法
class Test5
{
private:
    int a;
public:
    //带参数的构造函数
    Test5(int a)
    {
        printf("\na:%d", a);
    }
    Test5(int a, int b)
    {
        printf("\na:%d b:%d", a, b);
    }
public:
};

int main55()
{
    Test5 t1(10);  //c++编译器默认调用有参构造函数 括号法
    Test5 t2 = (20, 10); //c++编译器默认调用有参构造函数 等号法
    Test5 t3 = Test5(30); //程序员手工调用构造函数 产生了一个对象 直接调用构造构造函数法

    system("pause");
    return 0;
}
3拷贝构造函数调用时机
赋值构造函数的四种调用场景（调用时机）
第1和第2个调用场景
#include "iostream"
using namespace std;

class AA
{
public:
    AA() //无参构造函数 默认构造函数
    {    
        cout<<"我是构造函数，自动被调用了"<<endl;
    }
    AA(int _a) //无参构造函数 默认构造函数
    {    
        a = _a;
    }
    AA(const AA &obj2)
    {
        cout<<"我也是构造函数，我是通过另外一个对象obj2，来初始化我自己"<<endl;
        a = obj2.a + 10;
    }
    ~AA()
    {
        cout<<"我是析构函数，自动被调用了"<<endl;
    }
    void getA()
    {
        printf("a:%d \n", a);
    }
protected:
private:
    int a;
};
//单独搭建一个舞台
void ObjPlay01()
{
    AA a1; //变量定义
    
    //赋值构造函数的第一个应用场景
    //用对象1 初始化 对象2
    AA a2 = a1; //定义变量并初始化 //初始化法

    a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
}

第二个应用场景
//单独搭建一个舞台
void ObjPlay02()
{
    AA a1(10); //变量定义

    //赋值构造函数的第一个应用场景
    //用对象1 初始化 对象2
    AA a2(a1); //定义变量并初始化 //括号法

    //a2 = a1; //用a1来=号给a2 编译器给我们提供的浅copy
    a2.getA();
}
//注意：初始化操作 和 等号操作 是两个不同的概念

第3个调用场景
#include "iostream"
using namespace std;

class Location
{
public:
    Location( int xx = 0 , int yy = 0 )
    {
        X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;
    }
    Location( const Location & p )         //复制构造函数
    {
        X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;  
    }
    ~Location()
    {
        cout << X << "," << Y << " Object destroyed." << endl ;
    }
    int  GetX () { return X ; }        int GetY () { return Y ; }
private :   int  X , Y ;
} ;

//alt + f8 排版
void f ( Location  p )   
{
    cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}

void mainobjplay()
{  
    Location A ( 1, 2 ) ;  //形参是一个元素，函数调用，会执行实参变量初始化形参变量
    f ( A ) ;
}

void main()
{  
    mainobjplay();
    system("pause");
}


第4个调用场景
第四个应用场景
#include "iostream"
using namespace std;
class Location
{
public:
    Location( int xx = 0 , int yy = 0 )
    {
        X = xx ;  Y = yy ;  cout << "Constructor Object.\n" ;
    }
    Location( const Location & p )         //复制构造函数
    {
        X = p.X ;  Y = p.Y ;   cout << "Copy_constructor called." << endl ;  
    }
    ~Location()
    {
        cout << X << "," << Y << " Object destroyed." << endl ;
    }
    int  GetX () { return X ; }        int GetY () { return Y ; }
private :   int  X , Y ;
} ;

//alt + f8 排版
void f ( Location  p )   
{
    cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl ;
}

Location g()
{
    Location A(1, 2);
    return A;
}

//对象初始化操作 和 =等号操作 是两个不同的概念
//匿名对象的去和留，关键看，返回时如何接
void mainobjplay()
{  
    //若返回的匿名对象，赋值给另外一个同类型的对象，那么匿名对象会被析构
    //Location B;
    //B = g();  //用匿名对象 赋值 给B对象，然后匿名对象析构

    //若返回的匿名对象，来初始化另外一个同类型的对象，那么匿名对象会直接转成新的对象
    Location B = g();
    cout<<"传智扫地僧测试"<<endl;
}

void main()
{  
    mainobjplay();
    system("pause");
}

4默认构造函数
二个特殊的构造函数
1）默认无参构造函数
当类中没有定义构造函数时，编译器默认提供一个无参构造函数，并且其函数体为空
2）默认拷贝构造函数
当类中没有定义拷贝构造函数时，编译器默认提供一个默认拷贝构造函数，简单的进行成员变量的值复制
3.3构造函数调用规则研究
1）当类中没有定义任何一个构造函数时，c++编译器会提供默认无参构造函数和默认拷贝构造函数
2）当类中定义了拷贝构造函数时，c++编译器不会提供无参数构造函数
3） 当类中定义了任意的非拷贝构造函数（即：当类中提供了有参构造函数或无参构造函数），c++编译器不会提供默认无参构造函数
4 ）默认拷贝构造函数成员变量简单赋值
总结：只要你写了构造函数，那么你必须用。

构造析构阶段性总结
1）构造函数是C++中用于初始化对象状态的特殊函数
2）构造函数在对象创建时自动被调用
3）构造函数和普通成员函数都遵循重载规则
4）拷贝构造函数是对象正确初始化的重要保证
5）必要的时候，必须手工编写拷贝构造函数
========》1个对象的初始化讲完了，增加一个案例。
3.4深拷贝和浅拷贝
默认复制构造函数可以完成对象的数据成员值简单的复制
 对象的数据资源是由指针指示的堆时，默认复制构造函数仅作指针值复制
1浅拷贝问题抛出和分析
深拷贝浅拷贝现象出现的原因
2浅拷贝程序C++提供的解决方法
显示提供copy构造函数
显示操作重载=号操作，不使用编译器提供的浅copy

class Name
{
public:
    Name(const char *pname)
    {
        size = strlen(pname);
        pName = (char *)malloc(size + 1);
        strcpy(pName, pname);
    }
    Name(Name &obj)
    {
        //用obj来初始化自己
        pName = (char *)malloc(obj.size + 1);
        strcpy(pName, obj.pName);
        size = obj.size;
    }
    ~Name()
    {
        cout<<"开始析构"<<endl;
        if (pName!=NULL)
        {
            free(pName);
            pName = NULL;
            size = 0;
        }
    }

    void operator=(Name &obj3)
    {
        if (pName != NULL)
        {
            free(pName);
            pName = NULL;
            size = 0;
        }
        cout<<"测试有没有调用我。。。。"<<endl;

        //用obj3来=自己
        pName = (char *)malloc(obj3.size + 1);
        strcpy(pName, obj3.pName);
        size = obj3.size;
    }  

protected:
private:
    char *pName;
    int size;
};

//对象的初始化 和 对象之间=号操作是两个不同的概念
void playObj()
{
    Name obj1("obj1.....");
    Name obj2 = obj1; //obj2创建并初始化

    Name obj3("obj3...");

    //重载=号操作符
    obj2 = obj3; //=号操作

    cout<<"业务操作。。。5000"<<endl;

}
void main61()
{
    playObj();
    system("pause");
}



3.5多个对象构造和析构
1对象初始化列表  
1）对象初始化列表出现原因
1.必须这样做：
如果我们有一个类成员，它本身是一个类或者是一个结构，而且这个成员它只有一个带参数的构造函数，没有默认构造函数。这时要对这个类成员进行初始化，就必须调用这个类成员的带参数的构造函数，
如果没有初始化列表，那么他将无法完成第一步，就会报错。

2、类成员中若有const修饰，必须在对象初始化的时候，给const int m 赋值
当类成员中含有一个const对象时，或者是一个引用时，他们也必须要通过成员初始化列表进行初始化，
因为这两种对象要在声明后马上初始化，而在构造函数中，做的是对他们的赋值，这样是不被允许的。
2）C++中提供初始化列表对成员变量进行初始化
语法规则
Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3)
{
    // some other assignment operation
}
3）注意概念
初始化：被初始化的对象正在创建
赋值：被赋值的对象已经存在

4）注意：
成员变量的初始化顺序与声明的顺序相关，与在初始化列表中的顺序无关
初始化列表先于构造函数的函数体执行

/*
1 C++中提供了初始化列表对成员变量进行初始化
2 使用初始化列表出现原因：
1.必须这样做：
如果我们有一个类成员，它本身是一个类或者是一个结构，而且这个成员它只有一个带参数的构造函数，
而没有默认构造函数，这时要对这个类成员进行初始化，就必须调用这个类成员的带参数的构造函数，
如果没有初始化列表，那么他将无法完成第一步，就会报错。

2、类成员中若有const修饰，必须在对象初始化的时候，给const int m 赋值
当类成员中含有一个const对象时，或者是一个引用时，他们也必须要通过成员初始化列表进行初始化，
因为这两种对象要在声明后马上初始化，而在构造函数中，做的是对他们的赋值，这样是不被允许的。
*/

//总结 构造和析构的调用顺序

#include "iostream"
using namespace std;

class ABC
{
public:
    ABC(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        printf("a:%d,b:%d,c:%d \n", a, b, c);
        printf("ABC construct ..\n");
    }
    ~ABC()
    {
        printf("a:%d,b:%d,c:%d \n", a, b, c);
        printf("~ABC() ..\n");
    }
protected:
private:
    int a;
    int b;
    int c;
};


class MyD
{
public:
    MyD():abc1(1,2,3),abc2(4,5,6),m(100)
    //MyD()
    {
        cout<<"MyD()"<<endl;
    }
    ~MyD()
    {
        cout<<"~MyD()"<<endl;
    }

protected:
private:
    ABC abc1; //c++编译器不知道如何构造abc1
    ABC abc2;
    const int m;
};


int run()
{
    MyD myD;
    return 0;
}

int main_dem03()
{
    
    run();
    system("pause");
    return 0;
}
3.6构造函数和析构函数的调用顺序研究
构造函数与析构函数的调用顺序
1）当类中有成员变量是其它类的对象时，首先调用成员变量的构造函数，调用顺序与声明顺序相同；之后调用自身类的构造函数
2）析构函数的调用顺序与对应的构造函数调用顺序相反
3.7构造函数和析构函数综合练习
通过训练，把所学知识点都穿起来
1构造析综合训练
demo10_构造析构练习强化.cpp    （讲解）
    展示分析过程，注意赋值构函数的调用
2匿名对象强化训练
    demo10_构造析构练习强化.cpp
1）匿名对象生命周期
2）匿名对象的去和留
3匿名对象强化训练
3）构造中调用构造
demo11_匿名对象练习强化.cpp
    构造函数中调用构造函数，是一个蹩脚的行为。
3.8 对象的动态建立和释放
1 new和delete基本语法
1）在软件开发过程中，常常需要动态地分配和撤销内存空间，例如对动态链表中结点的插入与删除。在C语言中是利用库函数malloc和free来分配和撤销内存空间的。C++提供了较简便而功能较强的运算符new和delete来取代malloc和free函数。
注意： new和delete是运算符，不是函数，因此执行效率高。

2）虽然为了与C语言兼容，C++仍保留malloc和free函数，但建议用户不用malloc和free函数，而用new和delete运算符。new运算符的例子：
new int;  //开辟一个存放整数的存储空间，返回一个指向该存储空间的地址(即指针)
new int(100);  //开辟一个存放整数的空间，并指定该整数的初值为100，返回一个指向该存储空间的地址
new char[10];  //开辟一个存放字符数组(包括10个元素)的空间，返回首元素的地址
new int[5][4];  //开辟一个存放二维整型数组(大小为5*4)的空间，返回首元素的地址
float *p=new float (3.14159);  //开辟一个存放单精度数的空间，并指定该实数的初值为//3.14159，将返回的该空间的地址赋给指针变量p
       3）new和delete运算符使用的一般格式为：
   
用new分配数组空间时不能指定初值。如果由于内存不足等原因而无法正常分配空间，则new会返回一个空指针NULL，用户可以根据该指针的值判断分配空间是否成功。
4）应用举例

2 类对象的动态建立和释放
使用类名定义的对象都是静态的，在程序运行过程中，对象所占的空间是不能随时释放的。但有时人们希望在需要用到对象时才建立对象，在不需要用该对象时就撤销它，释放它所占的内存空间以供别的数据使用。这样可提高内存空间的利用率。
    C++中，可以用new运算符动态建立对象，用delete运算符撤销对象
比如：
Box *pt;  //定义一个指向Box类对象的指针变量pt
    pt=new Box;  //在pt中存放了新建对象的起始地址
在程序中就可以通过pt访问这个新建的对象。如
    cout<<pt->height;  //输出该对象的height成员
    cout<<pt->volume( );  //调用该对象的volume函数，计算并输出体积
C++还允许在执行new时，对新建立的对象进行初始化。如
    Box *pt=new Box(12,15,18);
这种写法是把上面两个语句(定义指针变量和用new建立新对象)合并为一个语句，并指定初值。这样更精炼。
新对象中的height，width和length分别获得初值12,15,18。调用对象既可以通过对象名，也可以通过指针。
    在执行new运算时，如果内存量不足，无法开辟所需的内存空间，目前大多数C++编译系统都使new返回一个0指针值。只要检测返回值是否为0，就可判断分配内存是否成功。
    ANSI C++标准提出，在执行new出现故障时，就“抛出”一个“异常”，用户可根据异常进行有关处理。但C++标准仍然允许在出现new故障时返回0指针值。当前，不同的编译系统对new故障的处理方法是不同的。
在不再需要使用由new建立的对象时，可以用delete运算符予以释放。如
delete pt; //释放pt指向的内存空间
这就撤销了pt指向的对象。此后程序不能再使用该对象。
如果用一个指针变量pt先后指向不同的动态对象，应注意指针变量的当前指向，以免删错了对象。在执行delete运算符时，在释放内存空间之前，自动调用析构函数，完成有关善后清理工作。
3 编程实践
//1  malloc free函数            c关键字
//    new delete 操作符号         c++的关键字

//2 new 在堆上分配内存  delete
//分配基础类型 、分配数组类型、分配对象

//3 new和malloc 深入分析
混用测试、异同比较
结论：    malloc不会调用类的构造函数
        Free不会调用类的析构函数

4静态成员变量成员函数
思考：每个变量，拥有属性。有没有一些属性，归所有对象拥有？
4.1静态成员变量
1）定义静态成员变量
关键字 static 可以用于说明一个类的成员，
        静态成员提供了一个同类对象的共享机制
 把一个类的成员说明为 static 时，这个类无论有多少个对象被创建，这些对象共享这个 static 成员
 静态成员局部于类，它不是对象成员

例如：
#include<iostream>
using namespace std;
class  counter
{     
static  int  num ; //声明与定义静态数据成员
  public :
      void  setnum ( int i ) { num = i ; }     //成员函数访问静态数据成员
      void  shownum() { cout << num << '\t' ; }
} ;
int  counter :: num = 0 ;//声明与定义静态数据成员
void main ()
{   counter  a , b ;
    a.shownum() ; //调用成员函数访问私有静态数据成员
    b.shownum() ;
    a.setnum(10) ;
    a.shownum() ;
    b.shownum() ;
}

从结果可以看出，访问的是同一个静态数据成员

2）使用静态成员变量
// 例5-14  使用公有静态数据成员
#include<iostream.h>
class  counter
{ public :
      counter (int a) { mem = a; }
      int mem;        //公有数据成员
      static  int  Smem ;    //公有静态数据成员
} ;
int  counter :: Smem = 1 ;    //初始值为1
void main()
{   counter c(5);
    int i ;
    for( i = 0 ; i < 5 ; i ++ )
      { counter::Smem += i ;
         cout << counter::Smem << '\t' ;  //访问静态成员变量方法2
      }
    cout<<endl;
    cout<<"c.Smem = "<<c.Smem<<endl; //访问静态成员变量方法1
    cout<<"c.mem = "<<c.mem<<endl;
}
4.2静态成员函数
1）概念
静态成员函数数冠以关键字static
 静态成员函数提供不依赖于类数据结构的共同操作，它没有this指针
 在类外调用静态成员函数用 “类名 :: ”作限定词，或通过对象调用
2）案例

3）疑难问题：静态成员函数中，不能使用普通变量。
    //静态成员变量属于整个类的，分不清楚，是那个具体对象的属性。

4.3综合训练


5 C++面向对象模型初探
前言
C++对象模型可以概括为以下2部分：
1. 语言中直接支持面向对象程序设计的部分，主要涉及如构造函数、析构函数、虚函数、继承（单继承、多继承、虚继承）、多态等等。
2. 对于各种支持的底层实现机制。
在c语言中，“数据”和“处理数据的操作（函数）”是分开来声明的，也就是说，语言本身并没有支持“数据和函数”之间的关联性。在c++中，通过抽象数据类型（abstract data type，ADT），在类中定义数据和函数，来实现数据和函数直接的绑定。
概括来说，在C++类中有两种成员数据：static、nonstatic；三种成员函数：static、nonstatic、virtual。

5.1基础知识
C++中的class从面向对象理论出发，将变量(属性)和函数(方法)集中定义在一起，用于描述现实世界中的类。从计算机的角度，程序依然由数据段和代码段构成。
C++编译器如何完成面向对象理论到计算机程序的转化？
换句话：C++编译器是如何管理类、对象、类和对象之间的关系
具体的说：具体对象调用类中的方法，那，c++编译器是如何区分，是那个具体的类，调用这个方法那?
思考一下程序结果
#include "iostream"

using namespace std;

class C1
{
public:
    int i;  //4
    int j; //4
    int k;  //4
protected:
private:
}; //12

class C2
{
public:
    int i;
    int j;
    int k;
    
    static int m; //4
public:
    int getK() const { return k; } //4
    void setK(int val) { k = val; }  //4

protected:
private:
}; //24 16 12(铁钉的不对)

struct S1
{
    int i;
    int j;
    int k;
}; //

struct S2
{
    int i;
    int j;
    int k;
    static int m;
}; //

int main()
{
    printf("c1:%d \n", sizeof(C1));
    printf("c2:%d \n", sizeof(C2));
    printf("s1:%d \n", sizeof(S1));
    printf("s2:%d \n", sizeof(S2));
    
    system("pause");
}
5.2编译器对属性和方法的处理机制
通过上面的案例，我们可以的得出：
1）C++类对象中的成员变量和成员函数是分开存储的
成员变量：
普通成员变量：存储于对象中，与struct变量有相同的内存布局和字节对齐方式
静态成员变量：存储于全局数据区中
成员函数：存储于代码段中。
问题出来了：很多对象共用一块代码？代码是如何区分具体对象的那？

换句话说：int getK() const { return k; }，代码是如何区分，具体obj1、obj2、obj3对象的k值？

2）C++编译器对普通成员函数的内部处理

请仔细思考，并说出你的总结！
5.3总结
1、C++类对象中的成员变量和成员函数是分开存储的。C语言中的内存四区模型仍然有效！
2、C++中类的普通成员函数都隐式包含一个指向当前对象的this指针。
3、静态成员函数、成员变量属于类
静态成员函数与普通成员函数的区别
静态成员函数不包含指向具体对象的指针
普通成员函数包含一个指向具体对象的指针

5.4 this指针


实验1：若类成员函数的形参 和 类的属性，名字相同，通过this指针来解决。
实验2：类的成员函数可通过const修饰，请问const修饰的是谁
5.5全局函数PK成员函数
    1、把全局函数转化成成员函数，通过this指针隐藏左操作数
        Test add(Test &t1, Test &t2)===》Test add(Test &t2)
    2、把成员函数转换成全局函数，多了一个参数
        void printAB()===》void printAB(Test *pthis)
    3、函数返回元素和返回引用
            Test& add(Test &t2) //*this //函数返回引用
            {
                this->a = this->a + t2.getA();
                this->b = this->b + t2.getB();
                return *this; //*操作让this指针回到元素状态
            }

            Test add2(Test &t2) //*this //函数返回元素
            {
                //t3是局部变量
                Test t3(this->a+t2.getA(), this->b + t2.getB()) ;
                return t3;
            }

6友元
6.1友元函数


例如


class A1
{
public:
    A1()
    {
        a1 = 100;
        a2 = 200;
    }
    int getA1()
    {
        return this->a1;
    }
    //声明一个友元函数
    friend void setA1(A1 *p, int a1); //这个函数是这个类的好朋友
    
protected:
private:
    int a1;
    int a2;
};

void setA1(A1 *p, int a1)
{
    p->a1 = a1;
}
void main()
{
    A1 mya1;
    cout<<mya1.getA1()<<endl;
    setA1(&mya1, 300); //通过友元函数 修改A类的私有属性
    cout<<mya1.getA1()<<endl;

    system("pause");
}


6.2友元类
若B类是A类的友员类，则B类的所有成员函数都是A类的友员函数
友员类通常设计为一种对数据操作或类之间传递消息的辅助类


7强化训练
1 static关键字强化训练题
某商店经销一种货物。货物购进和卖出时以箱为单位，各箱的重量不一样，因此，商店需要记录目前库存的总重量。现在用C++模拟商店货物购进和卖出的情况。

#include "iostream"
using namespace std;

class Goods
{
public :
    Goods ( int  w) { weight = w ;  total_weight += w ; }
    ~ Goods() { total_weight -= weight ; }
    int  Weight() { return  weight ; } ;    
    static  int  TotalWeight() { return  total_weight ; }  
    Goods *next ;
private :
    int  weight ;
    static  int  total_weight ;
} ;

int  Goods::total_weight = 0 ;

//r尾部指针
void purchase( Goods * &f, Goods *& r, int w )
{
    Goods *p = new Goods(w) ;
    p -> next = NULL ;
    if ( f == NULL )  f = r = p ;
    else { r -> next = p ;    r = r -> next ; } //尾部指针下移或新结点变成尾部结点
}
void sale( Goods * & f , Goods * & r )
{
    if ( f == NULL ) { cout << "No any goods!\n" ;  return ; }
    Goods *q = f ;  f = f -> next ;  delete q ;
    cout << "saled.\n" ;
}

void main()
{
    Goods * front = NULL , * rear = NULL ;
    int  w ;  int  choice ;
    do
    {
        cout << "Please choice:\n" ;
        cout << "Key in 1 is purchase,\nKey in 2 is sale,\nKey in 0 is over.\n" ;
        cin >> choice ;
        switch ( choice )        // 操作选择
        {
        case 1 :                           // 键入1，购进1箱货物
            {  cout << "Input weight: " ;
            cin >> w ;
            purchase( front, rear, w ) ;         // 从表尾插入1个结点
            break ;
            }
        case 2 :                     // 键入2，售出1箱货物
            { sale( front, rear ) ;    break ; }       // 从表头删除1个结点
        case 0 :  break ;                     // 键入0，结束
        }
        cout << "Now total weight is:" << Goods::TotalWeight() << endl ;
    } while ( choice ) ;
}

2 数组类封装
目标：解决实际问题，训练构造函数、copy构造函数等，为操作符重载做准备

数组类的测试
#include "iostream"
#include "Array.h"
using namespace std;

int main()
{
    Array a1(10);
    
    for(int i=0; i<a1.length(); i++)
    {
        a1.setData(i, i);
    }
    
    for(int i=0; i<a1.length(); i++)
    {
        printf("array %d: %d\n", i, a1.getData(i));
    }
    
    Array a2 = a1;
    
    for(int i=0; i<a2.length(); i++)
    {
        printf("array %d: %d\n", i, a2.getData(i));
    }
    
    system("pause");
    return 0;
}

数组类的头文件
#ifndef _MYARRAY_H_
#define _MYARRAY_H_
class Array
{
private:
    int mLength;
int* mSpace;

public:
    Array(int length);
    Array(const Array& obj);
    int length();
    void setData(int index, int value);
    int getData(int index);
    ~Array();
};

#endif

3小结
类通常用关键字class定义。类是数据成员和成员函数的封装。类的实例称为对象。
结构类型用关键字struct定义，是由不同类型数据组成的数据类型。
 类成员由private, protected, public决定访问特性。public成员集称为接口。
 构造函数在创建和初始化对象时自动调用。析构函数则在对象作用域结束时自动调用。
 重载构造函数和复制构造函数提供了创建对象的不同初始化方式。
 静态成员是局部于类的成员，提供一种同类对象的共享机制。
友员用关键字friend声明。友员是对类操作的一种辅助手段。一个类的友员可以访问该类各种性质的成员。
链表是一种重要的动态数据结构，可以在程序运行时创建或撤消数据元素。

8运算符重载
8.1概念
什么是运算符重载

所谓重载，就是重新赋予新的含义。函数重载就是对一个已有的函数赋予新的含义，使之实现新功能，因此，一个函数名就可以用来代表不同功能的函数，也就是”一名多用”。

运算符也可以重载。实际上，我们已经在不知不觉之中使用了运算符重载。例如，大 家都已习惯于用加法运算符”+”对整数、单精度数和双精度数进行加法运算，如5+8， 5.8 +3.67等，其实计算机对整数、单精度数和双精度数的加法操作过程是很不相同的， 但由于C++已经对运算符”+”进行了重载，所以就能适用于int, float, doUble类型的运算。

又如”<<“是C++的位运算中的位移运算符（左移），但在输出操作中又是与流对 象cout 配合使用的流插入运算符，”>>“也是位移运算符(右移），但在输入操作中又是与流对象 cin 配合使用的流提取运算符。这就是运算符重载(operator overloading)。C++系统对”<<“和”>>“进行了重载，用户在不同的场合下使用它们时，作用是不同 的。对”<<“和”>>“的重载处理是放在头文件stream中的。因此，如果要在程序中用”<< “和”>>”作流插入运算符和流提取运算符，必须在本文件模块中包含头文件stream(当然还应当包括”using namespace std“)。
现在要讨论的问题是：用户能否根据自己的需要对C++已提供的运算符进行重载，赋予它们新的含义，使之一名多用。？

运算符重载入门技术推演
1为什么会用运算符重载机制
    用复数类举例
//Complex c3 = c1 + c2;
//原因 Complex是用户自定义类型，编译器根本不知道如何进行加减
    //编译器给提供了一种机制，让用户自己去完成，自定义类型的加减操作。。。。。
    //这个机制就是运算符重载机制
2 运算符重载的本质是一个函数

class Complex
{
public:
    int a;
    int b;
    friend Complex operator+(Complex &c1, Complex &c2);
public:
    Complex(int a=0, int b=0)
    {
        this->a = a;
        this->b = b;
    }

public:
    void printCom()
    {
        cout<<a<<" + "<<b<<"i "<<endl;
    }

private:
};

/*
Complex myAdd(Complex &c1, Complex &c2)
{
    Complex tmp(c1.a+ c2.a, c1.b + c2.b);
    return tmp;
}
*/

Complex operator+(Complex &c1, Complex &c2)
{
    Complex tmp(c1.a+ c2.a, c1.b + c2.b);
    return tmp;
}

void main()
{
    Complex c1(1, 2), c2(3, 4);

    //Complex c3 = c1 + c2;  //用户自定义类型 编译器无法让变量相加
    //Complex myAdd(Complex &c1, Complex &c2);

    //1 普通函数
    //Complex c3 = myAdd(c1, c2);
    //c3.printCom();

    //2 operator+ 函数名称
    //Complex c3 = operator+(c1, c2);
    //c3.printCom();

    //3 +替换 函数名
    Complex c3 = c1 + c2; //思考C++编译器如何支持操作符重载机制的 (根据类型)
    c3.printCom();
{
int a =0, b = 0, c; //基础类型C++编译器知道如何加减
c = a +b;
}

    //4 把Complex类变成私有属性
    //友元函数的应用场景
    //friend Complex operator+(Complex &c1, Complex &c2);

    cout<<"hello..."<<endl;
    system("pause");
    return ;
}

8.2运算符重载的限制


8.3运算符重载编程基础

例如:
    //全局函数 完成 +操作符 重载
Complex operator+(Complex &c1, Complex &c2)
//类成员函数 完成 -操作符 重载
Complex operator-(Complex &c2)
运算符重载的两种方法



例如1:
//通过类成员函数完成-操作符重载
//函数声明 Complex operator-(Complex &c2)
//函数调用分析
//用类成员函数实现-运算符重载
    Complex c4 = c1 - c2;
    c4.printCom();
    //c1.operator-(c2);

例如2:
//通过全局函数方法完成+操作符重载
//函数声明 Complex operator+(Complex &c1, Complex &c2)
//函数调用分析
int main()
{
        Complex c1(1, 2), c2(3, 4);
        //Complex c31 = operator+(c1, c2);
Complex c3 = c1 + c2;
c3.printCom();
}
例如3: 学员自己练习 实现 * /


例如3
//前置++操作符 用全局函数实现
Complex& operator++(Complex &c1)
{
    c1.a ++;   
    c1.b ++;
    return c1;  
}
//调用方法
    ++c1 ; //=需要写出操作符重载函数原形
    c1.printCom();

//运算符重载函数名定义
    //首先承认操作符重载是一个函数 定义函数名operator++
    //分析函数参数 根据左右操作数的个数,operator++(Complex &c1)
    //分析函数返回值 Complex& operator++(Complex &c1) 返回它自身

例如4
//4.1前置—操作符 成员函数实现
Complex& operator--()
{
    this->a--;
    this->b--;
    return *this;
}

    //4.2调用方法
        --c1;
        c1.printCom();
    //4.3前置—运算符重载函数名定义
    //c1.operator--()

例如5
    //5.1 //后置++ 操作符 用全局函数实现
Complex operator++(Complex &c1, int)
{
    Complex tmp = c1;
    c1.a++;
    c1.b++;
    return tmp;
}
//5.2 调用方法
c1 ++ ; //先使用 后++
//5.3 后置++运算符重载函数名定义
Complex operator++(Complex &c1, int) //函数占位参数 和 前置++ 相区别

例如6
//6.1 后置— 操作符 用类成员函数实现
    Complex operator--(int)
    {
        Complex tmp = *this;
        this->a--;
        this->b--;
        return tmp;
    }
//6.2 调用方法
c1 ++ ; //先使用 后++
//6.3 后置--运算符重载函数名定义
Complex operator--(int) //函数占位参数 和 前置-- 相区别

前置和后置运算符总结
C++中通过一个占位参数来区分前置运算和后置运算

定义运算符重载函数名的步骤
全局函数、类成员函数方法实现运算符重载步骤
    1）要承认操作符重载是一个函数，写出函数名称operator+ ()
    2）根据操作数，写出函数参数
    3）根据业务，完善函数返回值(看函数是返回引用 还是指针 元素)，及实现函数业务
友元函数实现操作符重载的应用场景
1）友元函数和成员函数选择方法
当无法修改左操作数的类时，使用全局函数进行重载
=, [], ()和->操作符只能通过成员函数进行重载

2）用友元函数 重载 << >>操作符
istream 和 ostream 是 C++ 的预定义流类
cin 是 istream 的对象，cout 是 ostream 的对象
运算符 << 由ostream 重载为插入操作，用于输出基本类型数据
运算符 >> 由 istream 重载为提取操作，用于输入基本类型数据
用友员函数重载 << 和 >> ，输出和输入用户自定义的数据类型

a）用全局函数方法实现 << 操作符
ostream& operator<<(ostream &out, Complex &c1)
{
    //out<<"12345，生活真是苦"<<endl;
    out<<c1.a<<" + "<<c1.b<<"i "<<endl;
    return out;
}
//调用方法
cout<<c1;
//链式编程支持
cout<<c1<<"abcc";
//cout.operator<<(c1).operator<<("abcd");
//函数返回值充当左值 需要返回一个引用
b）类成员函数方法无法实现 << 操作符重载
        //因拿到cout这个类的源码
        //cout.operator<<(c1);

3）友元函数重载操作符使用注意点
a）友员函数重载运算符常用于运算符的左右操作数类型不同的情况

b）其他
在第一个参数需要隐式转换的情形下，使用友员函数重载运算符是正确的选择
 友员函数没有 this 指针，所需操作数都必须在参数表显式声明，很容易实现类型的隐式转换
 C++中不能用友员函数重载的运算符有
    =    （）    ［］    －>

4 ）友元函数案例vector类
#include <iostream>
using namespace std;

//为vector类重载流插入运算符和提取运算符
class vector
{
public :
    vector( int size =1 ) ;       
    ~vector() ;
    int & operator[]( int i ) ;
    friend ostream & operator << ( ostream & output , vector & ) ;
    friend istream & operator >> ( istream & input, vector & ) ;
private :  
    int * v ;     
    int len ;
};

vector::vector( int size )
{
    if (size <= 0 || size > 100 )
    {
        cout << "The size of " << size << " is null !\n" ; abort() ;  
    }
    v = new int[ size ] ;  len = size ;
}

vector :: ~vector()
{
    delete[] v ;  
    len = 0 ;
}

int &vector::operator[]( int i )         
{
    if( i >=0 && i < len )  return v[ i ] ;
    cout << "The subscript " << i << " is outside !\n" ;  abort() ;
}
ostream & operator << ( ostream & output, vector & ary )
{
    for(int i = 0 ; i < ary.len ; i ++ )  
        output << ary[ i ] << "  " ;
    output << endl ;
    return output ;
}
istream & operator >> ( istream & input, vector & ary )    
{
    for( int i = 0 ; i < ary.len ; i ++ )  
        input >> ary[ i ] ;
    return  input ;
}

void main()
{
    int k ;
    cout << "Input the length of vector A :\n" ;     
    cin >> k ;
    vector A( k ) ;
    cout << "Input the elements of vector A :\n" ;     
    cin >> A ;
    cout << "Output the elements of vector A :\n" ;
    cout << A ;
    system("pause");
}

8.4运算符重载提高
1运算符重载机制
C++编译器是如何支持操作符重载机制的?
2重载赋值运算符=
赋值运算符重载用于对象数据的复制
 operator= 必须重载为成员函数
重载函数原型为：
    类型  &  类名  :: operator= ( const  类名 & ) ;
案例：完善Name类，支持=号操作。

结论:
    1 //先释放旧的内存
    2 返回一个引用
    3 =操作符 从右向左
    //obj3 = obj1;  // C++编译器提供的 等号操作 也属 浅拷贝
// obj4 = obj3 = obj1
    //obj3.operator=(obj1)

    Name& operator=(Name &obj1)
    {
        //1 先释放obj3旧的内存
        if (this->m_p != NULL)
        {
            delete[] m_p;
            m_len = 0;
        }
        //2 根据obj1分配内存大小
        this->m_len = obj1.m_len;
        this->m_p = new char [m_len+1];
        
        //3把obj1赋值给obj3
        strcpy(m_p, obj1.m_p);
        return *this;
    }

3重载数组下表运算符[]
重载[]和()运算符
运算符 [] 和 () 是二元运算符
 [] 和 () 只能用成员函数重载，不能用友元函数重载
重载下标运算符 []
[] 运算符用于访问数据对象的元素
重载格式    类型  类 :: operator[]  ( 类型 ) ；

设 x 是类 X 的一个对象，则表达式
        x [ y ]
    可被解释为
        x . operator [ ] ( y )



4重载函数调用符 ()
() 运算符用于函数调用
重载格式    类型  类 :: operator()  ( 表达式表  ) ；
例1
    设 x 是类 X 的一个对象，则表达式
        x ( arg1, arg2, … )
    可被解释为
        x . operator () (arg1, arg2, … )
案例：
//例2：用重载()运算符实现数学函数的抽象
#include <iostream>
class  F
  { public :  
        double  operator ( )  ( double x ,  double  y ) ;
  } ;
double  F :: operator ( )  ( double  x ,  double  y )
   { return   x * x + y * y ; }
void main ( )            
{
F  f  ;
f.getA();
      cout << f ( 5.2 , 2.5 ) << endl ;  // f . operator() (5.2, 2.5)
}

比较普通成员函数
//例3  用重载()运算符实现 pk 成员函数
#include <iostream.h>
class  F
  { public :  
        double  memFun ( double x ,  double  y ) ;
  } ;
double  F :: memFun ( double  x ,  double  y )
   { return   x * x + y * y ; }
void main ( )            
{
F  f  ;
       cout << f.memFun ( 5.2 , 2.5 ) << endl ;
}
5为什么不要重载&&和||操作符
理论知识：
1）&&和||是C++中非常特殊的操作符
2）&&和||内置实现了短路规则
3）操作符重载是靠函数重载来完成的
4）操作数作为函数参数传递
5）C++的函数参数都会被求值，无法实现短路规则
#include <cstdlib>
#include <iostream>

using namespace std;

class Test
{
    int i;
public:
    Test(int i)
    {
        this->i = i;
    }

    Test operator+ (const Test& obj)
    {
        Test ret(0);

        cout<<"执行+号重载函数"<<endl;
        ret.i = i + obj.i;
        return ret;
    }

    bool operator&& (const Test& obj)
    {
        cout<<"执行&&重载函数"<<endl;
        return i && obj.i;
    }
};

// && 从左向右
void main()
{
    int a1 = 0;
    int a2 = 1;

    cout<<"注意：&&操作符的结合顺序是从左向右"<<endl;

    if( a1 && (a1 + a2) )
    {
        cout<<"有一个是假，则不在执行下一个表达式的计算"<<endl;
    }

    Test t1 = 0;
    Test t2 = 1;

    If ( t1 && (t1 + t2) )
    {
      //t1  && t1.operator(t2)
      // t1.operator(  t1.operator(t2)  )   
        cout<<"两个函数都被执行了，而且是先执行了+"<<endl;
    }

    system("pause");
    return ;
}


8.5运算符重载在项目开发中的应用
1实现一个数组类
添加<< >>
2实现一个字符串类
构造函数要求
MyString a;
MyString a(“dddd”);
MyString b = a;

常用的操作符
<<  >>  !=  ==  >  <  =
//C语言中 没有字符串这种类型，是通过数组来模拟字符串
//C++中 我们来设计一个字符串 以零结尾的字符串

class MyString
{
    friend ostream& operator<<(ostream &out, const MyString &s);
public: //构造和析构
    MyString(int len = 0);
    MyString(const char *p);
    MyString(const MyString& obj);
    ~MyString();

public: //操作符重载
    MyString& operator=(const char *p);
    MyString& operator=(const MyString& obj);
    char& operator[](int index) const;

public:
    bool operator==(const char* p) const;
    bool operator!=(const char* p) const;
    bool operator==(const MyString& s) const;
    bool operator!=(const MyString& s) const;

public: //string to c
    char *c_str();
    const char* c_str() const;
    int length()
    {
        return m_len;
    }

public:
    int operator<(const char *p);
    int operator>(const char *p);

    int operator<(const MyString &s);
    int operator>(const MyString &s);

    
private:
    int        m_len;
    char    *m_p;
};

3智能指针类编写
1问题抛出
    指针使用过程中，经常会出现内存泄漏和内存多次被释放常
2 解决方案：例如：boost库的智能指针
    项目开发中，要求开发者使用预先编写的智能指针类对象代替C语言中的原生指针
3 智能指针思想
工程中的智能指针是一个类模板
    通过构造函数接管申请的内存
    通过析构函数确保堆内存被及时释放
    通过重载指针运算符* 和 -> 来模拟指针的行为
    通过重载比较运算符 == 和 != 来模拟指针的比较

class Test
{
public:
    Test()
    {
        this->a = 10;
    }
    void printT()
    {
        cout<<a<<endl;
    }

private:
    int a;
};

class MyTestPointer
{
public:
public:
    MyTestPointer()
    {
        p = NULL;
    }
    MyTestPointer(Test* p)
    {
        this->p = p;
    }
    ~MyTestPointer()
    {
        delete p;
    }
    Test* operator->()
    {
        return p;
    }
    Test& operator*()
    {
        return *p;
    }
    
protected:
    Test *p;
};

void main01_classp()
{
    Test *p = new Test;
    p->printT();
    delete p;

    MyTestPointer myp = new Test; //构造函数
    myp->printT(); //重载操作符 ->

};


class MyIntPointer
{
public:
public:
    MyIntPointer()
    {
        p = NULL;
    }
    MyIntPointer(int* p)
    {
        this->p = p;
    }
    ~MyIntPointer()
    {
        delete p;
    }
    int* operator->()
    {
        return p;
    }
    int& operator*()
    {
        return *p;
    }

protected:
    int *p;
};

void main02_intp()
{
    int *p = new int(100);
    cout<<*p<<endl;
    delete p;

    MyIntPointer myp = new int(200);
    cout<<*myp<<endl; //重载*操作符
};





8.7附录：运算符和结核性


总结
操作符重载是C++的强大特性之一
操作符重载的本质是通过函数扩展操作符的语义
operator关键字是操作符重载的关键
friend关键字可以对函数或类开发访问权限
操作符重载遵循函数重载的规则
操作符重载可以直接使用类的成员函数实现
=, [], ()和->操作符只能通过成员函数进行重载
++操作符通过一个int参数进行前置与后置的重载
C++中不要重载&&和||操作符





3、继承和派生
3.1继承概念
面向对象程序设计有4个主要特点：抽象、封装、继承和多态性。我们已经讲解了类和对象，了解了面向对象程序设计的两个重要特征一数据抽象与封装，已经能够设计出基于对象的程序，这是面向对象程序设计的基础。
要较好地进行面向对象程序设计，还必须了解面向对象程序设计另外两个重要特 征——继承性和多态性。本章主要介绍有关继承的知识，多态性将在后续章节中讲解。
继承性是面向对象程序设计最重要的特征，可以说，如果没有掌握继承性，就等于没有掌握类和对象的精华，就是没有掌握面向对象程序设计的真谛。
3.1.1类之间的关系
has-A，uses-A 和 is-A
has-A   包含关系，用以描述一个类由多个“部件类”构成。实现has-A关系用类成员表示，即一个类中的数据成员是另一种已经定义的类。
uses-A  一个类部分地使用另一个类。通过类之间成员函数的相互联系，定义友员或对象参数传递实现。
is-A   机制称为“继承”。关系具有传递性,不具有对称性。
3.1.2继承关系举例
万事万物中皆有继承，是重要的现象
两个案例：1）植物继承图；2）程序员继承图

3.1.3 继承相关概念

3.1.4 派生类的定义

注意：C++中的继承方式（public、private、protected）会影响子类的对外访问属性。

3.1.5 继承重要说明
1、子类拥有父类的所有成员变量和成员函数
4、子类可以拥有父类没有的方法和属性

2、子类就是一种特殊的父类
3、子类对象可以当作父类对象使用
3.2派生类的访问控制
派生类继承了基类的全部成员变量和成员方法（除了构造和析构之外的成员方法），但是这些成员的访问属性，在派生过程中是可以调整的。
3.2.1单个类的访问控制
1、类成员访问级别（public、private、protected）
2、思考：类成员的访问级别只有public和private是否足够？
3.2.2不同的继承方式会改变继承成员的访问属性
1）C++中的继承方式会影响子类的对外访问属性
public继承：父类成员在子类中保持原有访问级别
private继承：父类成员在子类中变为private成员
protected继承：父类中public成员会变成protected
              父类中protected成员仍然为protected
              父类中private成员仍然为private
2）private成员在子类中依然存在，但是却无法访问到。不论种方式继承基类，派生类都不能直接使用基类的私有成员 。
3）C++中子类对外访问属性表
    父类成员访问级别
继
承
方
式        public    proteced    private
    public    public    proteced    private
    proteced    proteced    proteced    private
    private    private    private    Private

4）继承中的访问控制

3.2.3“三看”原则
C++中的继承方式（public、private、protected）会影响子类的对外访问属性    
判断某一句话，能否被访问
    1）看调用语句，这句话写在子类的内部、外部
    2）看子类如何从父类继承（public、private、protected）    
    3）看父类中的访问级别（public、private、protected）
3.2.3派生类类成员访问级别设置的原则
    思考：如何恰当的使用public，protected和private为成员声明访问级别？
1、需要被外界访问的成员直接设置为public
2、只能在当前类中访问的成员设置为private
3、只能在当前类和子类中访问的成员设置为protected，protected成员的访问权限介于public和private之间。
3.2.4综合训练
练习：
public继承不会改变父类对外访问属性；
private继承会改变父类对外访问属性为private；
protected继承会部分改变父类对外访问属性。
结论：一般情况下class B : public A
//类的继承方式对子类对外访问属性影响

#include <cstdlib>
#include <iostream>

using namespace std;

class A
{
private:
    int a;
protected:
    int b;
public:
    int c;

    A()
    {
        a = 0;
        b = 0;
        c = 0;
    }

    void set(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

class B : public A
{
public:
    void print()
    {
        //cout<<"a = "<<a; //err
        cout<<"b = "<<b;
        cout<<"c = "<<endl;
    }
};

class C : protected A
{
public:
    void print()
    {
        //cout<<"a = "<<a; //err
        cout<<"b = "<<b;
        cout<<"c = "<<endl;
    }
};

class D : private A
{
public:
    void print()
    {
        //cout<<"a = "<<a; //err
        cout<<"b = "<<b<<endl;
        cout<<"c = "<<c<<endl;
    }
};

int main_01(int argc, char *argv[])
{
    A aa;
    B bb;
    C cc;
    D dd;

    aa.c = 100; //ok
    bb.c = 100; //ok
    //cc.c = 100; //err 类的外部是什么含义
    //dd.c = 100; //err

    aa.set(1, 2, 3);
    bb.set(10, 20, 30);
    //cc.set(40, 50, 60); //ee
    //dd.set(70, 80, 90); //ee

    bb.print();
    cc.print();
    dd.print();

    system("pause");
    return 0;
}
3.3继承中的构造和析构
3.3.1类型兼容性原则
类型兼容规则是指在需要基类对象的任何地方，都可以使用公有派生类的对象来替代。通过公有继承，派生类得到了基类中除构造函数、析构函数之外的所有成员。这样，公有派生类实际就具备了基类的所有功能，凡是基类能解决的问题，公有派生类都可以解决。类型兼容规则中所指的替代包括以下情况：
子类对象可以当作父类对象使用
子类对象可以直接赋值给父类对象
子类对象可以直接初始化父类对象
父类指针可以直接指向子类对象
父类引用可以直接引用子类对象
在替代之后，派生类对象就可以作为基类的对象使用，但是只能使用从基类继承的成员。
类型兼容规则是多态性的重要基础之一。

总结：子类就是特殊的父类 (base *p = &child;)
#include <cstdlib>
#include <iostream>

using namespace std;

/*
子类对象可以当作父类对象使用
    子类对象可以直接赋值给父类对象
    子类对象可以直接初始化父类对象
    父类指针可以直接指向子类对象
    父类引用可以直接引用子类对象
    */
//子类就是特殊的父类
class Parent03
{
protected:
    const char* name;
public:
    Parent03()
    {
        name = "Parent03";
    }

    void print()
    {
        cout<<"Name: "<<name<<endl;
    }
};

class Child03 : public Parent03
{
protected:
    int i;
public:
    Child03(int i)
    {
        this->name = "Child2";
        this->i = i;
    }
};

int main()
{
    Child03 child03(1000);
    //分别定义父类对象 父类指针 父类引用 child
    Parent03 parent = child03;
    Parent03* pp = &child03;
    Parent03& rp = child03;

    parent.print();
    pp->print();
    rp.print();
    system("pause");
    return 0;
}

3.3.2继承中的对象模型
类在C++编译器的内部可以理解为结构体
子类是由父类成员叠加子类新成员得到的




继承中构造和析构
问题：如何初始化父类成员？父类与子类的构造函数有什么关系
    在子类对象构造时，需要调用父类构造函数对其继承得来的成员进行初始化
    在子类对象析构时，需要调用父类析构函数对其继承得来的成员进行清理
#include <cstdlib>
#include <iostream>
using namespace std;

class Parent04
{
public:
    Parent04(const char* s)
    {
        cout<<"Parent04()"<<" "<<s<<endl;
    }

    ~Parent04()
    {
        cout<<"~Parent04()"<<endl;
    }
};

class Child04 : public Parent04
{
public:
    Child04() : Parent04("Parameter from Child!")
    {
        cout<<"Child04()"<<endl;
    }

    ~Child04()
    {
        cout<<"~Child04()"<<endl;
    }
};

void run04()
{
    Child04 child;
}

int main_04(int argc, char *argv[])
{
    run04();

    system("pause");
    return 0;
}

3.3.3继承中的构造析构调用原则
1、子类对象在创建时会首先调用父类的构造函数
2、父类构造函数执行结束后，执行子类的构造函数
3、当父类的构造函数有参数时，需要在子类的初始化列表中显示调用
4、析构函数调用的先后顺序与构造函数相反
3.3.4继承与组合混搭情况下，构造和析构调用原则
    原则：    先构造父类，再构造成员变量、最后构造自己
             先析构自己，在析构成员变量、最后析构父类
            //先构造的对象，后释放
练习：demo05_extend_construct_destory.cpp

//子类对象如何初始化父类成员
//继承中的构造和析构
//继承和组合混搭情况下，构造函数、析构函数调用顺序研究

#include <iostream>

using namespace std;

class Object
{
public:
    Object(const char* s)
    {
        cout<<"Object()"<<" "<<s<<endl;
    }
    ~Object()
    {
        cout<<"~Object()"<<endl;
    }
};

class Parent : public Object
{
public:
    Parent(const char* s) : Object(s)
    {
        cout<<"Parent()"<<" "<<s<<endl;
    }
    ~Parent()
    {
        cout<<"~Parent()"<<endl;
    }
};

class Child : public Parent
{
protected:
    Object o1;
    Object o2;
public:
    Child() : o2("o2"), o1("o1"), Parent("Parameter from Child!")
    {
        cout<<"Child()"<<endl;
    }
    ~Child()
    {
        cout<<"~Child()"<<endl;
    }
};

void run05()
{
    Child child;
}

int main05(int argc, char *argv[])
{
    cout<<"demo05_extend_construct_destory.cpp"<<endl;
    run05();

    system("pause");
    return 0;
}
3.3.5继承中的同名成员变量处理方法
1、当子类成员变量与父类成员变量同名时
2、子类依然从父类继承同名成员
3、在子类中通过作用域分辨符::进行同名成员区分（在派生类中使用基类的同名成员，显式地使用类名限定符）
4、同名成员存储在内存中的不同位置



总结：同名成员变量和成员函数通过作用域分辨符进行区分

3.3.6派生类中的static关键字
继承和static关键字在一起会产生什么现象哪？
理论知识
基类定义的静态成员，将被所有派生类共享
根据静态成员自身的访问特性和派生类的继承方式，在类层次体系中具有不同的访问性质 （遵守派生类的访问控制）
 派生类中访问静态成员，用以下形式显式说明：
            类名 :: 成员
    或通过对象访问    对象名 . 成员




总结：
1> static函数也遵守3个访问原则
2> static易犯错误（不但要初始化，更重要的显示的告诉编译器分配内存）
3> 构造函数默认为private
3.4多继承
3.4.1多继承的应用
多继承概念
  一个类有多个直接基类的继承关系称为多继承
  多继承声明语法
class  派生类名 : 访问控制  基类名1 ,  访问控制  基类名2 ,  … , 访问控制  基类名n
    {
         数据成员和成员函数声明
    }；
  类 C 可以根据访问控制同时继承类 A 和类 B 的成员，并添加
     自己的成员

多继承的派生类构造和访问
多个基类的派生类构造函数可以用初始式调用基类构造函数初始化数据成员
执行顺序与单继承构造函数情况类似。多个直接基类构造函数执行顺序取决于定义派生类时指定的各个继承基类的顺序。
 一个派生类对象拥有多个直接或间接基类的成员。不同名成员访问不会出现二义性。如果不同的基类有同名成员，派生类对象访问时应该加以识别。

多继承简单应用



3.4.2虚继承
  如果一个派生类从多个基类派生，而这些基类又有一个共同的基类，则在对该基类中声明的名字进行访问时，可能产生二义性


分析：

总结：
  如果一个派生类从多个基类派生，而这些基类又有一个共同
     的基类，则在对该基类中声明的名字进行访问时，可能产生
     二义性
  如果在多条继承路径上有一个公共的基类，那么在继承路径的某处
     汇合点，这个公共基类就会在派生类的对象中产生多个基类子对象
  要使这个公共基类在派生类中只产生一个子对象，必须对这个基类
     声明为虚继承，使这个基类成为虚基类。
  虚继承声明使用关键字        virtual






实验：注意增加virtual关键字后，构造函数调用的次数。
3.5继承总结
继承是面向对象程序设计实现软件重用的重要方法。程序员可以在已有基类的基础上定义新的派生类。
 单继承的派生类只有一个基类。多继承的派生类有多个基类。
 派生类对基类成员的访问由继承方式和成员性质决定。
 创建派生类对象时，先调用基类构造函数初始化派生类中的基类成员。调用析构函数的次序和调用构造函数的次序相反。
 C++提供虚继承机制，防止类继承关系中成员访问的二义性。
 多继承提供了软件重用的强大功能，也增加了程序的复杂性。
4、多态
问题引出（赋值兼容性原则遇上函数重写）
    面向对象新需求
    C++提供的多态解决方案
    多态案例
    多态工程意义
        面向对象三大概念、三种境界（封装、继承、多态）
    多态成立条件
        总结条件、看代码的时候要看出多态
4.1多态
4.1.1问题引出
如果子类定义了与父类中原型相同的函数会发生什么？
函数重写
在子类中定义与父类中原型相同的函数
函数重写只发生在父类与子类之间
class Parent
{
public:
     void print()
    {
        cout<<"Parent:print() do..."<<endl;
    }
};

class Child : public Parent
{
public:
     void print()
    {
        cout<<"Child:print() do..."<<endl;
    }
};
int main01()
{
    run00();

    /*
    Child child;
    Parent *p = NULL;
    p = &child;
    child.print();
    child.Parent::print();
    */

    system("pause");
    return 0;
}

父类中被重写的函数依然会继承给子类
默认情况下子类中重写的函数将隐藏父类中的函数
通过作用域分辨符::可以访问到父类中被隐藏的函数


/*
C/C++是静态编译型语言
在编译时，编译器自动根据指针的类型判断指向的是一个什么样的对象
*/
/*
1、在编译此函数的时，编译器不可能知道指针 p 究竟指向了什么。
2、编译器没有理由报错。
3、于是，编译器认为最安全的做法是编译到父类的print函数，因为父类和子类肯定都有相同的print函数。
*/

//面向对象新需求
//如果我传一个父类对象，执行父类的print函数
//如果我传一个子类对象，执行子类的printf函数


//现象产生的原因
//赋值兼容性原则遇上函数重写 出现的一个现象
//1 没有理由报错
//2 对被调用函数来讲，在编译器编译期间，我就确定了，这个函数的参数是p，是Parent类型的。。。
//3静态链编

//工程开发中如何判断是不是多态存在？

/*
在同一个类里面能实现函数重载
    继承的情况下，发生重写
    重载不一定;
重写的定义
    静态联编 重载是
    动态联编
*/
#include <iostream>

using namespace std;

class Parent
{
public:
     void print()
    {
        cout<<"Parent:print() do..."<<endl;
    }
};

class Child : public Parent
{
public:
     void print()
    {
        cout<<"Child:print() do..."<<endl;
    }
};

/*
1、在编译此函数的时，编译器不可能知道指针 p 究竟指向了什么。
2、编译器没有理由报错。
3、于是，编译器认为最安全的做法是编译到父类的print函数，因为父类和子类肯定都有相同的print函数。
*/

void howToPrint(Parent* p)
{
    p->print();
}

void run00()
{
    Child child;
    Parent* pp = &child;
    Parent& rp = child;

    //child.print();

    //通过指针
    //pp->print();
    //通过引用
    //rp.print();

    howToPrint(&child);
}
int main01()
{
    run00();

    /*
    Child child;
    Parent *p = NULL;
    p = &child;
    child.print();
    child.Parent::print();
    */

    system("pause");
    return 0;
}

4.1.2面向对象新需求
编译器的做法不是我们期望的
    根据实际的对象类型来判断重写函数的调用
    如果父类指针指向的是父类对象则调用父类中定义的函数
    如果父类指针指向的是子类对象则调用子类中定义的重写函数

4.1.3解决方案
C++中通过virtual关键字对多态进行支持
使用virtual声明的函数被重写后即可展现多态特性
4.1.4多态实例
    
#include "iostream"
using namespace std;

class HeroFighter
{
public:
    
public:
    virtual int ackPower()
    {
        return 10;
    }
};

class AdvHeroFighter : public HeroFighter
{
public:
    virtual int ackPower()
    {
        return HeroFighter::ackPower()*2;
    }
};

class enemyFighter
{
public:
    int destoryPower()
    {
        return 15;
    }
};

//如果把这个结构放在动态库里面
//写了一个框架，可以调用
//我的第3代战机代码出现的时间晚于框架出现的时间。。。。
//框架 有使用后来人 写的代码的能力。。。
//面向对象3大概念
/*
封装
    突破了C语言函数的概念。。

继承
    代码复用 。。。。我复用原来写好的代码。。。

多态
    多态可以使用未来。。。。。80年代写了一个框架。。。。。。90人写的代码
    多态是我们软件行业追寻的一个目标。。。
////
*/
//
void objPK(HeroFighter *hf, enemyFighter *enemyF)
{
    if (hf->ackPower() >enemyF->destoryPower())
    {
        printf("英雄打败敌人。。。胜利\n");
    }
    else
    {
        printf("英雄。。。牺牲\n");
    }
}

void main()
{
    HeroFighter hf;
    enemyFighter ef;

    objPK(&hf, &ef);

    AdvHeroFighter advhf;

    objPK(&advhf, &ef);
    system("pause");
}

4.1.5多态工程意义
//面向对象3大概念
/*
封装
    突破了C语言函数的概念。。

继承
    代码复用 。。。。我复用原来写好的代码。。。

多态
    多态可以使用未来。。。。。80年代写了一个框架。。。。。。90人写的代码
    多态是我们软件行业追寻的一个目标。。。
    //写了一个框架，可以调用后来人，写的代码的能力
////
*/
4.1.6多态成立的条件
//间接赋值成立的3个条件
//1 定义两个变量。。。
//2 建立关联 。。。。
//3 *p

//多态成立的三个条件
//1 要有继承
//2 要有函数重写。。。C 虚函数
//3 要有父类指针（父类引用）指向子类对象
//多态是设计模式的基础，多态是框架的基础   
4.1.7多态的理论基础
01静态联编和动态联编
1、联编是指一个程序模块、代码之间互相关联的过程。
2、静态联编（static binding），是程序的匹配、连接在编译阶段实现，也称为早期匹配。
    重载函数使用静态联编。
3、动态联编是指程序联编推迟到运行时进行，所以又称为晚期联编（迟绑定）。
switch 语句和 if 语句是动态联编的例子。
4、理论联系实际
1、C++与C相同，是静态编译型语言
2、在编译时，编译器自动根据指针的类型判断指向的是一个什么样的对象；所以编译器认为父类指针指向的是父类对象。
3、由于程序没有运行，所以不可能知道父类指针指向的具体是父类对象还是子类对象
从程序安全的角度，编译器假设父类指针只指向父类对象，因此编译的结果为调用父类的成员函数。这种特性就是静态联编。
4.2多态相关面试题
面试题1：请谈谈你对多态的理解
多态的实现效果
多态：同样的调用语句有多种不同的表现形态；
多态实现的三个条件
    有继承、有virtual重写、有父类指针（引用）指向子类对象。
多态的C++实现
   virtual关键字，告诉编译器这个函数要支持多态；不是根据指针类型判断如何调用；而是要根据指针所指向的实际对象类型来判断如何调用
多态的理论基础
   动态联编PK静态联编。根据实际的对象类型来判断重写函数的调用。
多态的重要意义
   设计模式的基础 是框架的基石。
实现多态的理论基础
  函数指针做函数参数
C函数指针是C++至高无上的荣耀。C函数指针一般有两种用法（正、反）。
多态原理探究
  与面试官展开讨论

面试题2：谈谈C++编译器是如何实现多态                    
c++编译器多态实现原理
面试题3：谈谈你对重写，重载理解
函数重载
必须在同一个类中进行
子类无法重载父类的函数，父类同名函数将被名称覆盖
重载是在编译期间根据参数类型和个数决定函数调用
函数重写
必须发生于父类与子类之间
并且父类与子类中的函数必须有完全相同的原型
使用virtual声明之后能够产生多态(如果不使用virtual，那叫重定义)
多态是在运行期间根据具体对象的类型决定函数调用

#include <cstdlib>
#include <iostream>

using namespace std;

class Parent01
{
public:
    Parent01()
    {
        cout<<"Parent01:printf()..do"<<endl;
    }
public:
    virtual void func()
    {
        cout<<"Parent01:void func()"<<endl;
    }

    virtual void func(int i)
    {
        cout<<"Parent:void func(int i)"<<endl;
    }

    virtual void func(int i, int j)
    {
        cout<<"Parent:void func(int i, int j)"<<endl;
    }
};

class Child01 : public Parent01
{

public:
    
    //此处2个参数，和子类func函数是什么关系
    void func(int i, int j)
    {
        cout<<"Child:void func(int i, int j)"<<" "<<i + j<<endl;
    }

    //此处3个参数的，和子类func函数是什么关系
    void func(int i, int j, int k)
    {
        cout<<"Child:void func(int i, int j, int k)"<<" "<<i + j + k<<endl;
    }
};

void run01(Parent01* p)
{
    p->func(1, 2);
}

int main()
{
    Parent01 p;

    p.func();
    p.func(1);
    p.func(1, 2);

    Child01 c;
    //c.func(); //问题1
    c.Parent01::func();
    c.func(1, 2);

    run01(&p);
    run01(&c);

    system("pause");
    return 0;
}

//问题1：child对象继承父类对象的func，请问这句话能运行吗？why
//c.func(); //因为名称覆盖，C++编译器不会去父类中寻找0个参数的func函数，只会在子类中找func函数。

//1子类里面的func无法重载父类里面的func
//2当父类和子类有相同的函数名、变量名出现，发生名称覆盖（子类的函数名，覆盖了父类的函数名。）
//3//c.Parent::func();
//问题2 子类的两个func和父类里的三个func函数是什么关系？
面试题4：是否可类的每个成员函数都声明为虚函数，为什么。            c++编译器多态实现原理
面试题5：构造函数中调用虚函数能实现多态吗？为什么？                c++编译器多态实现原理    
面试题6：虚函数表指针（VPTR）被编译器初始化的过程，你是如何理解的？
        c++编译器多态实现原理
面试题7：父类的构造函数中调用虚函数，能发生多态吗？                 c++编译器多态实现原理
面试题8：为什么要定义虚析构函数？
在什么情况下应当声明虚函数
构造函数不能是虚函数。建立一个派生类对象时，必须从类层次的根开始，沿着继承路径逐个调用基类的构造函数
 析构函数可以是虚的。虚析构函数用于指引 delete 运算符正确析构动态对象



其他
父类指针和子类指针的步长
1）铁律1：指针也只一种数据类型，C++类对象的指针p++/--，仍然可用。
2）指针运算是按照指针所指的类型进行的。
p++《=》p=p+1 //p = (unsigned int)basep + sizeof(*p) 步长。
3）结论：父类p++与子类p++步长不同；不要混搭，不要用父类指针++方式操作数组。

4.3多态原理探究
理论知识：
当类中声明虚函数时，编译器会在类中生成一个虚函数表
虚函数表是一个存储类成员函数指针的数据结构
虚函数表是由编译器自动生成与维护的
virtual成员函数会被编译器放入虚函数表中
当存在虚函数时，每个对象中都有一个指向虚函数表的指针（C++编译器给父类对象、子类对象提前布局vptr指针；当进行howToPrint(Parent *base)函数是，C++编译器不需要区分子类对象或者父类对象，只需要再base指针中，找vptr指针即可。）
VPTR一般作为类对象的第一个成员
4.3.1 多态的实现原理
C++中多态的实现原理
当类中声明虚函数时，编译器会在类中生成一个虚函数表
虚函数表是一个存储类成员函数指针的数据结构
虚函数表是由编译器自动生成与维护的
virtual成员函数会被编译器放入虚函数表中
存在虚函数时，每个对象中都有一个指向虚函数表的指针(vptr指针)



说明1：
通过虚函数表指针VPTR调用重写函数是在程序运行时进行的，因此需要通过寻址操作才能确定真正应该调用的函数。而普通成员函数是在编译时就确定了调用的函数。在效率上，虚函数的效率要低很多。
说明2：
出于效率考虑，没有必要将所有成员函数都声明为虚函数
说明3 ：C++编译器，执行HowToPrint函数，不需要区分是子类对象还是父类对象

4.3.2如何证明vptr指针的存在
#include <iostream>
using namespace std;

class A
{
public:
    void printf()
    {
        cout<<"aaa"<<endl;
    }
protected:
private:
    int a;
};

class B
{
public:
    virtual void printf()
    {
        cout<<"aaa"<<endl;
    }
protected:
private:
    int a;
};

void main()
{
    //加上virtual关键字 c++编译器会增加一个指向虚函数表的指针 。。。
    printf("sizeof(a):%d, sizeof(b):%d \n", sizeof(A), sizeof(B));
    cout<<"hello..."<<endl;
    system("pause");
    return ;
}
4.3.3构造函数中能调用虚函数，实现多态吗
1）对象中的VPTR指针什么时候被初始化？

对象在创建的时,由编译器对VPTR指针进行初始化
只有当对象的构造完全结束后VPTR的指向才最终确定
父类对象的VPTR指向父类虚函数表
子类对象的VPTR指向子类虚函数表

2）分析过程
   画图分析


5、纯虚函数和抽象类
5.1基本概念



5.2抽象类案例



5.3抽象类在多继承中的应用
C++中没有Java中的接口概念，抽象类可以模拟Java中的接口类。（接口和协议）
5.3.1有关多继承的说明  
工程上的多继承
被实际开发经验抛弃的多继承
工程开发中真正意义上的多继承是几乎不被使用的
多重继承带来的代码复杂性远多于其带来的便利
多重继承对代码维护性上的影响是灾难性的
在设计方法上，任何多继承都可以用单继承代替
多继承中的二义性和多继承不能解决的问题

5.3.2多继承的应用场景
C++中是否有Java中的接口概念？
绝大多数面向对象语言都不支持多继承
绝大多数面向对象语言都支持接口的概念
C++中没有接口的概念
C++中可以使用纯虚函数实现接口
接口类中只有函数原型定义，没有任何数据的定义。
class Interface
{
    public:
        virtual void func1() = 0;
        virtual void func2(int i) = 0;
        virtual void func3(int i) = 0;
};
实际工程经验证明
多重继承接口不会带来二义性和复杂性等问题  
多重继承可以通过精心设计用单继承和接口来代替
接口类只是一个功能说明，而不是功能实现。
子类需要根据功能说明定义功能实现。
#include "iostream"
using namespace std;

/*
C++中没有接口的概念
C++中可以使用纯虚函数实现接口
接口类中只有函数原型定义，没有任何数据的定义。
*/

class Interface1
{
public:
    virtual void print() = 0;
    virtual int add(int a, int b) = 0;
};

class Interface2
{
public:
    virtual void print() = 0;
    virtual int add(int a, int b) = 0;
    virtual int minus(int a, int b) = 0;
};

class parent
{
public:
    int a;
};
class Child : public parent, public Interface1, public Interface2
{
public:  
    void print()
    {
        cout<<"Child::print"<<endl;
    }

    int add(int a, int b)
    {
        return a + b;
    }

    int minus(int a, int b)
    {
        return a - b;
    }
};

int main()
{
    Child c;

    c.print();

    cout<<c.add(3, 5)<<endl;
    cout<<c.minus(4, 6)<<endl;

    Interface1* i1 = &c;  
    Interface2* i2 = &c;

    cout<<i1->add(7, 8)<<endl;
    cout<<i2->add(7, 8)<<endl;
    system("pause");
}
5.4抽象类知识点强化
/*
编写一个C++程序, 计算程序员( programmer )工资
    1 要求能计算出初级程序员( junior_programmer ) 中级程序员 ( mid_programmer )高级程序员( adv_programmer)的工资
    2 要求利用抽象类统一界面,方便程序的扩展, 比如:新增, 计算 架构师 (architect ) 的工资
*/
5.5面向抽象类编程思想强化
理论知识
虚函数和多态性使成员函数根据调用对象的类型产生不同的动作
 多态性特别适合于实现分层结构的软件系统，便于对问题抽象时   定义共性，实现时定义区别
面向抽象类编程（面向接口编程）是项目开发中重要技能之一。
5.4.1案例：socket库c++模型设计和实现
企业信息系统框架集成第三方产品
案例背景：一般的企业信息系统都有成熟的框架。软件框架一般不发生变化，能自由的集成第三方厂商的产品。
案例需求：请你在企业信息系统框架中集成第三方厂商的Socket通信产品和第三方厂商加密产品。
第三方厂商的Socket通信产品：完成两点之间的通信；
第三方厂商加密产品：完成数据发送时加密；数据解密时解密。


案例要求：    1）能支持多个厂商的Socket通信产品入围
            2）能支持多个第三方厂商加密产品的入围
            3）企业信息系统框架不轻易发生框架

需求实现
        思考1：企业信息系统框架、第三方产品如何分层
思考2：企业信息系统框架，如何自由集成第三方产品
（软件设计：模块要求松、接口要求紧）
        思考3：软件分成以后，开发企业信息系统框架的程序员，应该做什么？
                第三方产品入围应该做什么？

编码实现
        分析有多少个类    CSocketProtocol     CSckFactoryImp1     CSckFactoryImp2
CEncDesProtocol     HwEncdes     ciscoEncdes
1、定义 CSocketProtocol  抽象类
2、编写框架函数
3、编写框架测试函数
4、厂商1（CSckFactoryImp1）实现CSocketProtocol、厂商2（CSckFactoryImp1）实现CSocketProtoco
5、抽象加密接口（CEncDesProtocol）、加密厂商1(CHwImp)、加密厂商2(CCiscoImp))，集成实现业务模型
6、框架（c语言函数方式，框架函数；c++类方式，框架类）

几个重要的面向对象思想
继承-组合（强弱）
注入
控制反转 IOC
MVC
        面向对象思想扩展aop思想
            aop思想是对继承编程思想的有力的补充
5.4.2案例：计算员工工资

5.4.3案例：计算几何体的表面积和体积


5.6 C面向接口编程和C多态
友情提示：今天课程内容，更加贴近实战，并且语法和软件思想都较难，请学员紧跟思路。课后加强复习！
结论：    只要你动手，又很容易！
5.6.1函数类型语法基础
函数三要素： 名称、参数、返回值
C语言中的函数有自己特定的类型
C语言中通过typedef为函数类型重命名
typedef type name(parameter list)
typedef int f(int, int);
typedef void p(int);
函数指针
函数指针用于指向一个函数
函数名是函数体的入口地址
1)可通过函数类型定义函数指针: FuncType* pointer;
2)也可以直接定义：type (*pointer)(parameter list);
pointer为函数指针变量名
type为指向函数的返回值类型
parameter list为指向函数的参数类型列表
函数指针语法梳理
//函数类型
//函数指针类型
//函数指针变量

数组指针语法梳理  
//数组类型语法
//数组指针类型
//数组指针变量


typedef int(FUNC)(int);

int test(int i)
{
    return i * i;
}

void f()
{
    printf("Call f()...\n");
}

int main()
{
    FUNC* pt = test;
    
    void(*pf)() = &f;
    
    pf();
    (*pf)();
    
    printf("Function pointer call: %d\n", pt(3));
}
5.6.2函数指针做函数参数
1、指针做函数参数pk函数指针做函数参数
回忆指针做函数参数
一级指针做函数参数、二级。。。。、三级
2、函数指针做函数参数
当函数指针 做为函数的参数，传递给一个被调用函数，
被调用函数就可以通过这个指针调用外部的函数，这就形成了回调
3、练习
int add(int a, int b);
int libfun(int (*pDis)(int a, int b));

int main(void)
{
int (*pfun)(int a, int b);
pfun = add;
libfun(pfun);

}

int add(int a, int b)
{
return a + b;

}

int libfun(int (*pDis)(int a, int b))
{
    int a, b;
    a = 1;
    b = 2;
add(1,3)  //直接调用add函数
printf("%d", pDis(a, b)); //通过函数指针做函数参数,间接调用add函数
//思考 这样写 pDis(a, b)有什么好处?
}
//剖析思路
//1函数的调用 和 函数的实现  有效的分离
//2 C++的多态,可扩展

现在这几个函数是在同一个文件当中
假如
int libfun(int (*pDis)(int a, int b))
是一个库中的函数，就只有使用回调了，通过函数指针参数将外部函数地址传入
来实现调用

函数 add 的代码作了修改，也不必改动库的代码，就可以正常实现调用
便于程序的维护和升级

回调函数思想：

结论：回调函数的本质：提前做了一个协议的约定（把函数的参数、函数返回值提前约定）
请思考：C编译器通过那个具体的语法，实现解耦合的？
    C++编译器通过多态的机制(提前布局vptr指针和虚函数表,找虚函数入口地址来实现)
5.6.3函数指针正向调用
1、函数指针做函数参数，调用方式
被调用函数和主调函数在同一文件中（用来教学，没有任何意义）
2、函数指针做函数参数
被调用函数和主调函数不在同一个文件中、模块中。
难点：理解被调用函数是什么机制被调用起来的。框架
框架提前设置了被调用函数的入口（框架提供了第三方模块入口地址的集成功能）
框架具备调用第三方模块入口函数
3、练习

typedef int (*EncDataFunc)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen);

int MyEncDataFunc(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen)
{
    int rv = 0;
    char *p = "222222222222";
    
    strcpy(outData, p);
    *outDataLen = strlen(p);
    return rv;
}

int Send_Data(EncDataFunc encDataFunc, unsigned char *inData, int inDataLen, unsigned char *outData, int *outDatalen)
{
    int rv = 0;
    if (encDataFunc != NULL)
    {
        rv = encDataFunc(inData, inDataLen, outData, outDatalen,  NULL, 0);
        if (rv != 0)
        {
            printf("func encDataFunc() err.\n");
            return rv;
        }
    }
    return rv;
}

int main()
{
    int rv = 0;

    EncDataFunc encDataFunc = NULL;
    encDataFunc = MyEncDataFunc;

    // 第一个调用
    {
        unsigned char inData[2048];
        int inDataLen;
        unsigned char outData[2048];
        int outDatalen;
        strcpy(inData, "1111");
        inDataLen = strlen(inData);
        rv = encDataFunc(inData,inDataLen, outData, &outDatalen, NULL, 0);
        if (rv != 0)
        {
            printf("edf err .....\n");
        }
        else
        {
            printf("edf ok \n");
            printf("%s \n", outData);
        }
    }

    {
         unsigned char inData[2048];
         int inDataLen;
         unsigned char outData[2048];
          int outDatalen;
          strcpy(inData, "3333");
          inDataLen = strlen(inData);
          rv =  Send_Data(MyEncDataFunc, inData, inDataLen, outData, &outDatalen);
          if (rv != 0)
          {
              printf("func Send_Data err:%d", rv);
              return rv;
          }
          printf("%s \n", outData);
    }

    getchar();
}
5.6.4函数指针反向调用
回调函数效果展示。
5.6.5.C动态库升级成框架案例
C语言版本Socket动态库升级成框架集成第三方产品
简称：C动态库升级成框架案例
名字解释    
    动态库：抽象类一个套接口，单独封装成模块，供别人调用；无法扩展。
    框架：能自由的扩展

案例背景：一般的企业信息系统都有成熟的框架，可以有C语言写，也可以由C++语言。软件框架一般不发生变化，能自由的集成第三方厂商的产品。

案例需求：在socket通信库中，完成数据加密功能，有n个厂商的加密产品供你选择，如何实现动态库和第三个厂商产品的解耦合。
提醒：C++通过抽象类，也就是面向抽象类编程实现的（相当于C++编译器通过多态机制，已经很好用了。提前布局vptr指针、虚函数表；调用是迟绑定完成。），
C语言中如何实现哪？

案例要求：    1）能支持多个第三方厂商加密产品的入围
            2）企业信息系统框架不轻易发生框架

需求实现思路分析
        思考1：企业信息系统框架、第三方产品如何分层
思考2：企业信息系统框架，如何自由集成第三方产品
（软件设计：模块要求松、接口要求紧）
        思考3：软件分层确定后，动态库应该做什么？产品入围厂商应该做什么？
以后，开发企业信息系统框架的程序员，应该做什么？
                第三方产品入围应该做什么？
编码实现
        
1、动态库中定义协议，并完成任务的调用
typedef int (*EncData)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen);
typedef int (*DecData)(unsigned char *inData,int inDataLen,unsigned char *outData,int *outDataLen,void *Ref, int RefLen);
2、加密厂商完成协议函数的编写
3、对接调试。
4、动态库中可以缓存第三方函数的入口地址，也可以不缓存，两种实现方式。
案例总结
    回调函数：利用函数指针做函数参数，实现的一种调用机制，具体任务的实现者，可以不知道什么时候被调用。
    回调机制原理：
        当具体事件发生时，调用者通过函数指针调用具体函数
        回调机制的将调用者和被调函数分开，两者互不依赖
        任务的实现 和 任务的调用 可以耦合  （提前进行接口的封装和设计）
5.6.6附录：诸葛亮的锦囊妙计
刘备利用周瑜、曹仁厮杀之际，乘虚袭取了南郡、荆州、襄阳，以后又征服了长沙等四郡。周瑜想想十分气恨，正无处报复以夺还荆州。不久，刘备忽然丧偶，周瑜计上心来，对孙权说：“您的妹妹，美丽、刚强，我们以联姻抗曹名义向刘备招亲，把他骗来南徐幽禁，逼他们拿荆州来换。”孙权大喜，郎派人到荆州说亲。
刘备认为这是骗局，想要拒绝，诸葛亮笑道：“送个好妻子上门何不答应？您只管去东吴，我叫赵云陪您去，自有安排，包您得了夫人又不失荆州。”
接着，诸葛亮暗暗关照赵云道：“我这里有三个锦囊，内藏三条妙计。到南徐时打开第一个，到年底时打开第二个，危急无路时打开第三个。”
第一个锦囊
    一到东吴就拜会乔国老
第二个锦囊
    刘备被孙权设计留下就对他谎称曹操大军压境
第三个锦囊
被东吴军队追赶就求孙夫人解围
