// 42 1610242852 15�� �ſ���
#include <iostream>
#include <cstring>
using namespace std;

class stu //3��ѧ��
{
public:
    void SetID(int i)
    {
        SID=i;
    }
    void Setname(char *n)
    {
        strcpy(name,n);
    }
    int GetID()
    {
        return SID;
    }
    char* Getname()
    {
        return name;
    }
private:
    int SID;
    char name[20];
};

class cou //5�ųɼ�
{
public:
    void Setname(char *Name)  //��������˽�б���
    {
        strcpy(name,Name);
    }
    void Setscore(int *s)
    { 
        score[0]=  //ע�⣬��һ��Ӧ�øĳ���Զ�Ӧ�±�����Ĵ�����ʽ
    }
    char* Getname()  //�������˽�б���
    {
        return name;
    }
    int* Getscore()
    {
        return score;
    }
private:
    char name[20];
    int score[3];

};


int main()
{
	stu student[3]={0};
	cou course[5]={0};
    for(int i=0;i<=4;i++)  //�ռ����ſγ�����
    {
        cout<<"Please input "<<i+1<<" names of course"<<endl;
        cin>>course[i].Setname();
    }
    for(int i=0;i<=2;i++)  //�ռ�ѧ����ID��name
    {
        cout<<"Please input "<<i+1<<" student's ID and name"<<endl;
        cin>>student[i].SetID();
        cin>>student[i].Setname();
    }
    for(int i=0;i<=2;i++)  //�ռ�ѧ�������ſγ̳ɼ�
    {
        for(int n=0;n<=4;n++)
        {
            cout<<"Please input "<<i+1<<" student's "<<n+1<<" score"<<endl;
            cin>>course[n].Getscore();
        }
    }
	int stumax1,stumax2,stumax3;  //�������ѧ������߳ɼ�
	for(int i=0;i<=2;i++) //����ÿλѧ����߳ɼ���Ӧ�Ŀγ�����
	{
		if(i==0)
		{
			for(int n=0;n<=4;n++)
			{
				if(n==0)
				{
					stumax1=course[n].Getscore[i];
				}
				if(stumax1<course[n].Getscore[i])
				{
					stumax1=course[n].Getscore[i];
				}
			}
		}
		if(i==1)
		{
			for(int n=0;n<=4;n++)
			{
				if(n==0)
				{
					stumax2=course[n].Getscore[i];
				}
				if(stumax2<course[n].Getscore[i])
				{
					stumax2=course[n].Getscore[i];
				}
			}
		}
		if(i==2)
		{
			for(int n=0;n<=4;n++)
			{
				if(n==0)
				{
					stumax3=course[n].Getscore[i];
				}
				if(stumax3<course[n].Getscore[i])
				{
					stumax3=course[n].Getscore[i];
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
					scomax1=course[n].Getscore[i];
				}
				if(scomax1<course[n].Getscore[i])
				{
					scomax1=course[n].Getscore[i];
				}
			}
		}

		if(i==1)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax2=course[n].Getscore[i];
				}
				if(scomax2<course[n].Getscore[i])
				{
					scomax2=course[n].Getscore[i];
				}
			}
		}
		if(i==2)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax3=course[n].Getscore[i];
				}
				if(scomax3<course[n].Getscore[i])
				{
					scomax3=course[n].Getscore[i];
				}
			}
		}
		if(i==3)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax4=course[n].Getscore[i];
				}
				if(scomax4<course[n].Getscore[i])
				{
					scomax4=course[n].Getscore[i];
				}
			}
		}
		if(i==4)
		{
			for(int n=0;n<=2;n++)
			{
				if(n==0)
				{
					scomax5=course[n].Getscore[i];
				}
				if(scomax5<course[n].Getscore[i])
				{
					scomax5=course[n].Getscore[i];
				}
			}
		}
	}
	cout<<"The score's order in three student is(from big to small)"<<" "<<stumax1<<" "<<stumax2<<" "<<stumax3<<endl;
	cout<<"The course's order in three student is(from big to small)"<<" "<<scomax1<<" "<<scomax2<<" "<<scomax3<<" "<<scomax4<<" "<<scomax5<<endl;
    return 0;
}
