#include <iostream> // standard input/output stream
#include <fstream> //file stream
using namespace std;

int main5()
{
    //==========write file============
    //open file
    ofstream fout("a.txt");//output file stream
    //���õ�����д�ļ���ʽ: ����д��(ios::out)��׷��д��(ios::app)

    //write file
    fout<<"Hello world."<<endl;
    fout<<"aa bb cc."<<endl;

    //close file
    fout.close();

    //==========read file============
    //open file
    ifstream fin("a.txt");//input file stream

    //read file
    //char str[200] = {0};
    string str;
    while(getline(fin,str))//���ж�ȡ
    //while(fin.getline(str,200))
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

int main()
{
    //==========write file============
    //open file
    ofstream fout("a.txt");//output file stream
    //���õ�����д�ļ���ʽ: ����д��(ios::out)��׷��д��(ios::app)

    //write file
    //fout<<123<<" "<<234<<endl;
    for(int i=1; i<=5; i++)
    {
        fout<<i<<" ";
    }

    //close file
    fout.close();

    //==========read file============
    //open file
    ifstream fin("a.txt");//input file stream

    //read file
    int a;
    while(fin>>a)
    {
        cout<<a<<endl;
    }

    //close file
    fin.close();

    return 0;
}

int main2()
{
    int a;
    cin>>a; //console input / standard input / keyboard input
    cout<<a<<endl;//console output / standard output // screen output
    return 0;
}


class Student
{
public:
    Student()
    {
        id = 0;
        cout<<"���캯��"<<endl;
    }
    ~Student()
    {
        cout<<"��������"<<endl;
    }

    void SetID(int i)
    {
        id = i;
    }
    int GetID()
    {
        return id;
    }
private:
    int id;
};

int main3()
{
    Student s;
    return 0;
}
