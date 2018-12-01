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
           //����д�ļ���ʽ������д��(ios::out)��׷��д��(ios::app)

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
    while(getline(fin,str))//���ж�ȡ
    {
        cout<<str<<endl;
    }
    /*
    while(fin>>str)//��ʶ�ȡ
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
                            //����д�ļ���ʽ������д�룬׷��д��

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
        cout<<"���캯��"<<endl;
    }
    ~Student()
    {
        cout<<"��������"<<endl;
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
