#include <iostream>//standard input/output stream
#include <cstring>
#include <string>
#include <fstream> //file stream

using namespace std;

int main()
{
    //=============write file===============
    //open file
    ofstream fout("a.txt");//output file stream
           //常用写文件方式：覆盖写入(ios::out)，追加写入(ios::app)

    //write file
    fout<<"Hello world."<<endl;
    fout<<"How do you do?"<<endl;

    //close file
    fout.close();

    //========read file==================
    //open file
    ifstream fin("a.txt");//input file stream

    //read file
    string str;
    while(getline(fin,str))//逐行读取
    {
        cout<<str<<endl;
    }
    /*
    while(fin>>str)//逐词读取
    {
        cout<<str<<endl;
    }
    */

    //close file
    fin.close();

    return 0;
}

int main2()
{
    //=============write file===============
    //open file
    ofstream fout("a.txt",ios::app);//output file stream
                            //常用写文件方式：覆盖写入，追加写入

    //write file
    fout<<"Hello world."<<endl;
    fout<<"How do you do?"<<endl;
    /*
    for(int i=1; i<=10; i++)
    {
        fout<<i<<"\t";
    }
    */

    //close file
    fout.close();

    //========read file==================
    //open file
    ifstream fin("a.txt");//input file stream

    //read file
    int b;
    while(fin>>b)
    {
        cout<<b<<endl;
    }
    /*char str[200] = {0};
    while(fin>>str)
    {
        cout<<str<<endl;
    }
    */

    //close file
    fin.close();


    return 0;
    int a;
    cin>>a;//console input
    cout<<a<<endl;//console output
    return 0;
}






class Student
{
public:
    Student()
    {
        id = 0;
        strcpy(name,"none");
        cout<<"构造函数"<<endl;
    }
    ~Student()
    {
        cout<<"析构函数"<<endl;
    }

private:
    int id;
    char name[20];
};

int main3()
{
    Student s;

    return 0;
}
