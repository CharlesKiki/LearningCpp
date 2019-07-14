#include <iostream>
#include <cstring> // for  strcpy()
#include <fstream> // for ifstream and ofstream

using namespace std;

class StudentClass
{
public:
    void SetID(int i)
    {
        SID = i;
    }
    void SetName(char* Name)
    {
        strcpy(name,Name);
    }
    void SetScore(int i,int s)
    {
        scores[i] = s;
    }
    int GetID()
    {
        return SID;
    }
    char* GetName()
    {
        return name;
    }
    int GetScore(int i)
    {
        return scores[i];
    }

private:
    int SID;
    char name[20];
    int scores[5];
};
//关键字class是数据类型说明符，指出下面说明的是类。标识符CGoods是商品这个类的类型名。花括号中是构成类体的一系列的成员，此处为数据成员；关键字public是一种访问限定符，表示其后所列为公共成员，就是说可以在外部对这些成员进行访问。

//在类中引进了成员函数（或称函数成员）(member function),也就是函数也成了数据(类)中的成员。成员函数可以直接使用类定义中的任一成员，可以处理数据成员，也可调用其他函数成员。

//类把数据（事物的属性）和函数（事物的行为——操作）封装为一个整体。 

int main0523()
{
    //Step1, define variables
    StudentClass s[3];

    //Step2, input
    int id;
    char name[20];
    int score;
    for(int i=0; i<=2; i++)
    {
        cout<<"Input the ID, name and 5 scores of student "<<i+1<<" : ";
        cin>>id>>name;
        s[i].SetID(id);
        s[i].SetName(name);
        for(int j=0; j<=4; j++)
        {
            cin>>score;
            s[i].SetScore(j,score);
        }
    }

    //Step3, process and output

    //to calculate the average score of each course
    int maxScore[5] = {0};
    int maxStuIndex[5] = {0};
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            int score = s[i].GetScore(j);
            if(score>maxScore[j])
            {
                maxScore[j] = score;
                maxStuIndex[j] = i;
            }
        }
    }
    for(int j=0; j<=4; j++)
    {
        int i = maxStuIndex[j];
        cout<<"Course "<<j+1<<" : maxStudent = "<<s[i].GetName()<<endl;
    }

    return 0;
}

//==============================2017.05.22========================

class Stu
{
public:
    int SID;
    char name[20];
    int scores[5];
};

int main0522()
{
    //Step1, define variables
    Stu s[3];

    //Step2, input
    for(int i=0; i<=2; i++)
    {
        cout<<"Input the ID, name and 5 scores of student "<<i+1<<" : ";
        cin>>s[i].SID>>s[i].name;
        for(int j=0; j<=4; j++)
        {
            cin>>s[i].scores[j];
        }
    }

    //Step3, process and output

    //to calculate the average score of each student
    for(int i=0; i<=2; i++)
    {
        int sum = 0;
        for(int j=0; j<=4; j++)
        {
            sum = sum + s[i].scores[j];
        }
        cout<<"Student "<<i+1<<" : ave = "<<sum/5.0<<endl;
    }

    //to calculate the average score of each course
    int a[5] = {0};
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            a[j] = a[j] + s[i].scores[j];
        }
    }
    for(int j=0; j<=4; j++)
    {
        cout<<"Course "<<j+1<<" : ave = "<<a[j]/3.0<<endl;
    }

    return 0;
}


//==============================2017.05.16/17========================

struct Student
{
    int SID;
    char name[20];
    int scores[5];
};

int main0517()
{
    //Step1, define variables
    Student s[3];
    char cNames[5][20] = {0};

    //Step2, input
    cout<<"Input the names of 5 courses ";
    for(int i=0; i<=4; i++)
    {
        cin>>cNames[i];
    }
    for(int i=0; i<=2; i++)
    {
        cout<<"Input the ID, name and 5 scores of student "<<i+1<<" : ";
        cin>>s[i].SID>>s[i].name;
        for(int j=0; j<=4; j++)
        {
            cin>>s[i].scores[j];
        }
    }

    //Step3, process and output

    //to calculate the average score of each student
    for(int i=0; i<=2; i++)
    {
        int sum = 0;
        int maxScore = -1;
        int maxIndex = -1;
        for(int j=0; j<=4; j++)
        {
            int score = s[i].scores[j];
            sum = sum + score;
            if(score>maxScore)
            {
                maxScore = score;
                maxIndex = j;
            }
        }
        cout<<"Student "<<i+1<<" : ave = "<<sum/5.0<<" , maxCourse = "<<cNames[maxIndex]<<endl;
    }

    //to calculate the average score of each course
    int a[5] = {0};
    int maxScore[5] = {0};
    int maxStuIndex[5] = {0};
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            int score = s[i].scores[j];
            a[j] = a[j] + score;
            if(score>maxScore[j])
            {
                maxScore[j] = score;
                maxStuIndex[j] = i;
            }
        }
    }
    for(int j=0; j<=4; j++)
    {
        int i = maxStuIndex[j];
        cout<<"Course "<<j+1<<" : ave = "<<a[j]/3.0<<" , maxStudent = "<<s[i].name<<endl;
    }

    return 0;
}

int main0516()
{
    //Step1, define variables
    Student s[3];

    //Step2, input
    for(int i=0; i<=2; i++)
    {
        cout<<"Input the ID, name and 5 scores of student "<<i+1<<" : ";
        cin>>s[i].SID>>s[i].name;
        for(int j=0; j<=4; j++)
        {
            cin>>s[i].scores[j];
        }
    }

    //Step3, process and output
    /*
           a[0] a[1] a[2] a[3] a[4]
    s[0] :  11   22   33   44   55
    s[1] :  22   33   44   55   66
    s[2] :  33   44   55   66   77
    */

    //to calculate the average score of each student
    for(int i=0; i<=2; i++)
    {
        int sum = 0;
        for(int j=0; j<=4; j++)
        {
            sum = sum + s[i].scores[j];
        }
        cout<<"Student "<<i+1<<" : ave = "<<sum/5.0<<endl;
    }

    //to calculate the average score of each course
    int a[5] = {0};
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            a[j] = a[j] + s[i].scores[j];
        }
    }
    for(int j=0; j<=4; j++)
    {
        cout<<"Course "<<j+1<<" : ave = "<<a[j]/3.0<<endl;
    }

    return 0;
}


////////////////////  风格代码
class CGoods
{
private :
       char Name[21] ;
       int Amount ;
       float Price ;
       float Total_value ;
public :
       void RegisterGoods(char*,int,float); //登记新商品，此处是函数头
       void CountTotal(void) ; //计算商品总价值
       void GetName(char*) ; //读取商品名
       int GetAmount(void) ; //读取商品数量
       float GetPrice(void) ; //读取商品单价
       float GetTotal_value(void) ; //读取商品总价值
};
只对成员函数作了一个声明，或者讲只给出了函数的原型，并没有对函数进行定义。函数定义通常在类的说明之后进行。
void CGoods::RegisterGoods(char* name,int amount, float price)
//登记新商品
{
    //char*是指向字符的指针类型说明，name现可理解为字符串
       strcpy(Name , name) ; //字符串拷贝函数
       Amount=amount ; Price=price ;
}

void CGoods::CountTotal(void) //计算商品总价值
{
       Total_value = Price*Amount;
}

void CGoods::GetName(char* name) //读取商品名
{
       strcpy(name , Name);
}

int CGoods::GetAmount(void) //读取商品数量
{
       return(Amount) ;
}
float CGoods::GetPrice(void) //读取商品单价
{
       return(Price) ;
}

float CGoods::GetTotal_value(void) //读取商品总价值
{
       return(Total_value) ;
}

在类函数外面定义成员函数