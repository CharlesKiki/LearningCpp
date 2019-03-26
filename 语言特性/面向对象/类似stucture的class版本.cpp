// 42 1610242852 15班 张俊祖
#include <iostream>

using namespace std;

class stu //3名学生
{
    public:
    int SID;
    char name[20];
};

class cou //5门成绩
{
    public:
    char name[20];
    int score[3];

};


int main()
{
	stu student[3]={0};
	cou course[5]={0};
    for(int i=0;i<=4;i++)  //收集五门课程名称
    {
        cout<<"Please input "<<i+1<<" names of course"<<endl;
        cin>>course[i].name;
    }
    for(int i=0;i<=2;i++)  //收集学生的ID和name
    {
        cout<<"Please input "<<i+1<<" student's ID and name"<<endl;
        cin>>student[i].SID;
        cin>>student[i].name;
    }
    for(int i=0;i<=2;i++)  //收集学生的五门课程成绩
    {
        for(int n=0;n<=4;n++)
        {
            cout<<"Please input "<<i+1<<" student's "<<n+1<<" score"<<endl;
            cin>>course[n].score[i];
        }
    }
    double Avestu[3]={0};
    double Avecou[5]={0};
    for(int i=0;i<2;i++)  //计算学生的平均成绩
    {
        for(int n;n<=5;n++)
        {
            Avestu[i] +=course[n].score[i];
        }
    }
    for(int i=0;i<=4;i++)  //计算课程的平均成绩
    {
        for(int n=0;n<=2;n++)
        {
            Avecou[i] +=course[i].score[n];
        }
    }
	int stumax1,stumax2,stumax3;  //存放三个学生的最高成绩
	for(int i=0;i<=2;i++) //计算每位学生最高成绩对应的课程名称
	{
		if(i==0)
		{
			for(int n=0;n<=4;n++)
			{
				if(n==0)
				{
					stumax1=course[n].score[i];
				}
				if(stumax1<course[n].score[i])
				{
					stumax1=course[n].score[i];
				}
			}
		}
		if(i==1)
		{
			for(int n=0;n<=4;n++)
			{
				if(n==0)
				{
					stumax2=course[n].score[i];
				}
				if(stumax2<course[n].score[i])
				{
					stumax2=course[n].score[i];
				}
			}
		}
		if(i==2)
		{
			for(int n=0;n<=4;n++)
			{
				if(n==0)
				{
					stumax3=course[n].score[i];
				}
				if(stumax3<course[n].score[i])
				{
					stumax3=course[n].score[i];
				}
			}
		}
	}
	int scomax1,scomax2,scomax3,scomax4,scomax5;
	scomax1=scomax2=scomax3=0;
	for(int i=0;i<=4;i++)
	{
		if(i==0)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax1=course[n].score[i];
				}
				if(scomax1<course[n].score[i])
				{
					scomax1=course[n].score[i];
				}
			}
		}

		if(i==1)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax2=course[n].score[i];
				}
				if(scomax2<course[n].score[i])
				{
					scomax2=course[n].score[i];
				}
			}
		}
		if(i==2)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax3=course[n].score[i];
				}
				if(scomax3<course[n].score[i])
				{
					scomax3=course[n].score[i];
				}
			}
		}
		if(i==3)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax4=course[n].score[i];
				}
				if(scomax4<course[n].score[i])
				{
					scomax4=course[n].score[i];
				}
			}
		}
		if(i==4)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax5=course[n].score[i];
				}
				if(scomax5<course[n].score[i])
				{
					scomax5=course[n].score[i];
				}
			}
		}
	}
	for(int i=0;i<=2;i++)
	{
		cout<<"The "<<i+1<<" student's average score is ： "<<Avestu[i]/3<<endl;
	}
	for(int i=0;i<=4;i++)
	{
		cout<<"The "<<i+1<<" class's average score is ： "<<Avecou[i]/5<<endl;
	}
	cout<<"The score's order in three student is(from big to small)"<<" "<<stumax1<<" "<<stumax2<<" "<<stumax3<<endl;
	cout<<"The course's order in three student is(from big to small)"<<" "<<scomax1<<" "<<scomax2<<" "<<scomax3<<" "<<scomax4<<" "<<scomax5<<endl;
    return 0;
}
