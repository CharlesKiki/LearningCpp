// 42 1610242852 15班 张俊祖
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
public:
    void SetID(int i)
    {
        SID=i;
    }
    void SetName(char *n)
    {
        strcpy(name,n);
    }
	void SetScore(int i,int s)
	{
		score[i]=s;
	}
    int GetID()
    {
        return SID;
    }
    char* Getname()
    {
        return name;
    }
	int GetScore(int i)
	{
		return score[i];
	}
private:
    int SID;
    char name[20];
	int score[5];
};

class Course //5门成绩
{
public:
    void Setname(char *Name)  //用于输入私有变量
    {
        strcpy(name,Name);
    }
    char* Getname()  //用于输出私有变量
    {
        return name;
    }
private:
    char name[20];
};

int main()
{
	//Step1, define variables
	Student student[3];
	Course course[5];
	int id;
	int score;
	char name[20]={0};
    for(int i=0;i<=4;i++)  //收集五门课程名称
    {
		cin>>name;
        cout<<"Please enter "<<i+1<<" names of course"<<endl;
        cin>>course[i].Setname(name);
    }
    for(int i=0;i<=2;i++)  //收集学生的ID和name
    {
        cout<<"Please enter "<<i+1<<"student's ID and name"<<endl;
        cin>>num;
		cin>>name[20];
        student[i].SetID(num);
        student[i].Setname(name);
    }
    for(int i=0;i<=2;i++)  //收集学生的五门课程成绩
    {
        for(int n=0;n<=4;n++)
        {
            cout<<"Please enter "<<i+1<<" student's "<<n+1<<" score"<<endl;
            cin>>num;
            course[n].Setscore(i,num);
        }
    }
//===========================process part=================================
	//比较最大的课程成绩
    for(int i=0; i<=2; i++)
    {
        int sum = 0;         //注意这里，每次都重新刷新了变量
        int maxScore = -1;   //巧妙，一定会让第一个成绩成为最大成绩
        int maxIndex = -1;
        for(int j=0; j<=4; j++)
        {
            int score = student[i].scores[j];  //传参处理
            sum = sum + score;  //求和处理
            if(score>maxScore)   //条件变量处理了最大值
            {
                maxScore = score;  //比较大小，更是为了找出最大的数组下标
                maxIndex = j;    //五门课程的第几门
            }
        }
        cout<<"Student "<<i+1<<" : ave = "<<sum/5.0<<" , maxCourse = "<<course[maxIndex].getname()<<endl;
    }
	
	//比较最好的学生成绩
	int temScore[5]=0;   //注意这里，没有刷新变量
	int maxscore[5] = {0}; //存放五门课程的最大成绩
	int maxStuIndex[5] = {0};
	for(int i=0;i<=2;i++)
	{
		for(int n=0;n<=4;n++)
		{
			int score = student[i].score[n];  //数组变量化处理
			temScore[i] = temScore[i] + score;  //计算学生的成绩和
			if(score>=maxScore[n])
			{
				maxScore[n] = score;
				maxStuIndex[n] = i;   //存疑？？
			}
		}
		
	}
    for(int j=0; j<=4; j++)
    {
        int i = maxStuIndex[j];
        cout<<"Course "<<j+1<<" : ave = "<<temScore[j]/3.0<<" , maxStudent = "<<student[i].name<<endl;
    }
    return 0;
}

