#include <iostream>

using namespace std;

struct Student //自定义结构类型名称
{//结构体定义
    int SID;//成员变量/属性
    char name[20];//成员变量/属性
};

void input(Student &s,int i)
{
    cout<<"Input SID of student "<<i+1<<" : ";
    cin>>s.SID;
    cout<<"Input name of student "<<i+1<<" : ";
    cin>>s.name;
}

void output(Student &s,int i)
{
    cout<<"SID of student "<<i+1<<" : "<<s.SID<<endl;
    cout<<"Name of student "<<i+1<<" : "<<s.name<<endl;
}

int main()
{
    Student s[3];

    for(int i=0; i<=2; i++)
    {
        input(s[i],i);
    }

    for(int i=0; i<=2; i++)
    {
        output(s[i],i);
    }


    return 0;
}


int main4()
{
    Student a;
    //input(a);
    //output(a);
    return 0;
}

int main3()
{
    Student s[3];

    for(int i=0; i<=2; i++)
    {
        cout<<"Input SID of student "<<i+1<<" : ";
        cin>>s[i].SID;
        cout<<"Input name of student "<<i+1<<" : ";
        cin>>s[i].name;
    }

    for(int i=0; i<=2; i++)
    {
        cout<<"SID of student "<<i+1<<" : "<<s[i].SID<<endl;
        cout<<"Name of student "<<i+1<<" : "<<s[i].name<<endl;
    }


    return 0;
}

int main2()
{
    /*
    int a = 2;
    double b = 3;
    int *p;
    p = &a; // *p <==> a
    *p = 3;
    a = 3;
    cout<<*p<<endl;//cout<<a<<endl;
    */


    Student s;//Student结构类型的变量
    Student *q;//Student结构类型的指针变量
    q = &s; // s <==> *q
    //cin>>s.SID;
    cin>>(*q).SID;
    //cin>>q->SID;
    //cin>>s.name;
    //cin>>(*q).name;
    cin>>q->name;
    cout<<s.SID<<endl;
    cout<<s.name<<endl;

    return 0;
}
