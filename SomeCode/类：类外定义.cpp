#include <iostream>
#include <cstring>

using namespace std;

//���Ա�����ַ���Ȩ��: public , protected , private
//Ĭ�ϵķ���Ȩ�ޣ� private
/*
����������ԣ���װ���̳У���̬
OOP: Object-Oriented Programming
C++, C#, Java
C��ϵ
*/
class Student
{
public://���г�Ա��
    //��Ա����
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

private://˽�г�Ա��
    //��Ա����
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
	student stu; //ʵ��������
	return 0��
	
}
///////////////�������Ļ���˼��
�ú����������

���ڶ������������

�������� inline  ��Ҫ��򵥵ĺ�����
��ͨ���� ���� �� ���� ����

���ڶ��� ������ڲ����ж���
������Ĭ�Ͻ����ں������� inline ����
���ⶨ�� ������д������ 
ͬ�ļ����ⶨ�� 
class car
{
	public:
	void run();
	void stop();
	
};
void car::run();{}   
void car::stop();{}

���ļ����ⶨ�壨רҵ���󲿷֣�
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
// ʵ�ַ�����ͷ�ļ�����
