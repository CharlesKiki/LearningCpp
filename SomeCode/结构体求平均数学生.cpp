// 42 1610242852 15班 张俊祖
#include <iostream>

using namespace std;

struct Student
{
    int UID;
    char NAME[20];  //注意报错，如果不使用数组会导致程序在第一个问题停止
    int SCORE[5];
};

int main()
{
    Student A,B,C;
    int AveStu[3]={0};
    double AveSco[5]={0};
    cout<<"Please enter the First sutdent's ID&name"<<endl;
    cin>>A.UID>>A.NAME;
    cout<<"Then enter the student's five score"<<endl;
    for(int i=0;i<=4;i++)
    {
        cin>>A.SCORE[i];
    }
    cout<<"Please enter the Second sutdent's ID&name"<<endl;
    cin>>B.UID>>B.NAME;
    cout<<"Then enter the student's five score"<<endl;
    for(int i=0;i<=04;i++)
    {
        cin>>B.SCORE[i];
    }
    cout<<"Please enter the Third sutdent's ID&name"<<endl;
    cin>>C.UID>>C.NAME;
    cout<<"Then enter the student's five score"<<endl;
    for(int i=0;i<=4;i++)
    {
        cin>>C.SCORE[i];
    }
	AveStu[0]=A.SCORE[1]+A.SCORE[2]+A.SCORE[3];
	AveStu[1]=B.SCORE[1]+B.SCORE[2]+B.SCORE[3];
	AveStu[2]=C.SCORE[1]+C.SCORE[2]+C.SCORE[3];
	for(int i=0;i<=2;i++)
	{
		cout<<"The "<<i+1<<"th student's average score is"<<AveStu[0]/3<<endl;
	}
	for(int i=0;i<=4;i++)
	{
		AveSco[i]=A.SCORE[i]+B.SCORE[i]+C.SCORE[i];
		cout<<"The "<<i+1<<" class average score is "<<AveSco[i]/3<<endl;
	}

    return 0;
}
