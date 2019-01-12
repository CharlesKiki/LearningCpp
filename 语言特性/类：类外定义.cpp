#include <iostream>
#include <cstring>

using namespace std;

//类成员的三种访问权限: public , protected , private
//默认的访问权限： private
/*
类的三个特性：封装，继承，多态
OOP: Object-Oriented Programming
C++, C#, Java
C语系
*/
class Student
{
public://公有成员区
    //成员函数
    void SetID(int i)
    {
        id = i;
    }
    void SetName(char *Name)
    {
        strcpy(name,Name);
    }
    int GetID()
    {
        return id;
    }
    char* GetName()
    {
        return name;
    }

private://私有成员区
    //成员变量
    int id;
    char name[20];
};

class Stu
{
public:
    bool SetID(int i)
    {
        if(i<0)
        {
            return false;
        }
        id = i;
        return true;
    }
    int GetID()
    {
        return id;
    }

private:
    int id;
};

class Stu2
{
public:
    int id;
};


int main()
{
    int a;
    cout<<"Input your ID : ";
    cin>>a;

    Stu s;
    bool bOK = s.SetID(a);
    if(bOK == false)
    {
        cout<<"Failed to set your ID."<<endl;
        return 0;
    }

    cout<<"Your ID is ";
    cout<<s.GetID()<<endl;

    return 0;
}
/////////////////////////
class student 
{
	public:
			string name;
			int age;
};

int main()
{
	student stu; //实例化对象
	return 0；
	
}
///////////////面向对象的基本思想
用函数代替操作

类内定义和内联函数

内联函数 inline  （要求简单的函数）
普通函数 调用 和 返回 部分

类内定义 在类的内部进行定义
编译器默认将类内函数进行 inline 处理
类外定义 函数体写在外面 
同文件类外定义 
class car
{
	public:
	void run();
	void stop();
	
};
void car::run();{}   
void car::stop();{}

分文件类外定义（专业，大部分）
car.h
class car
{
	public:
	void run();
	void stop();
	
};
car.cpp
#include "car.h"
void car::run();{}   
void car::stop();{}
// 实现方法和头文件分离
