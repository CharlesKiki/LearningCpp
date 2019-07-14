namespace NameSpaceA
{
    int a = 0;
}

namespace NameSpaceB
{
    int a = 1;

    namespace NameSpaceC
    {
        struct Teacher
        {
            char name[10];
            int age;
        };
    }
}

int main()
{
    using namespace NameSpaceA;
    using NameSpaceB::NameSpaceC::Teacher;

    printf("a = %d\n", a);
    printf("a = %d\n", NameSpaceB::a);

NameSpaceB::NameSpaceC::Teacher t2
    Teacher t1 = {"aaa", 3};

    printf("t1.name = %s\n", t1.name);
    printf("t1.age = %d\n", t1.age);

    system("pause");
    return 0;
}

4 结论
1）当使用<iostream>的时候，该头文件没有定义全局命名空间，必须使用namespace std；这样才能正确使用cout。若不引入using namespace std ,需要这样做。std::cout。
2）c++标准为了和C区别开，也为了正确使用命名空间，规定头文件不使用后缀.h。
3）C++命名空间的定义：    namespace name {  …  }
4）using namespace NameSpaceA;
5）namespce定义可嵌套。
4.2 “实用性”增加
#include "iostream"
using namespace std;

//C语言中的变量都必须在作用域开始的位置定义！！
//C++中更强调语言的“实用性”，所有的变量都可以在需要使用时再定义。

int main11()
{
    int i = 0;

    printf("ddd");
    int k;
    system("pause");
    return 0;
}