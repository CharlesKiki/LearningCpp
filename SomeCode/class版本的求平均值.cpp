// 42 1610242852 15�� �ſ���
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

class Course //5�ųɼ�
{
public:
    void Setname(char *Name)  //��������˽�б���
    {
        strcpy(name,Name);
    }
    char* Getname()  //�������˽�б���
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
    for(int i=0;i<=4;i++)  //�ռ����ſγ�����
    {
		cin>>name;
        cout<<"Please enter "<<i+1<<" names of course"<<endl;
        cin>>course[i].Setname(name);
    }
    for(int i=0;i<=2;i++)  //�ռ�ѧ����ID��name
    {
        cout<<"Please enter "<<i+1<<"student's ID and name"<<endl;
        cin>>num;
		cin>>name[20];
        student[i].SetID(num);
        student[i].Setname(name);
    }
    for(int i=0;i<=2;i++)  //�ռ�ѧ�������ſγ̳ɼ�
    {
        for(int n=0;n<=4;n++)
        {
            cout<<"Please enter "<<i+1<<" student's "<<n+1<<" score"<<endl;
            cin>>num;
            course[n].Setscore(i,num);
        }
    }
//===========================process part=================================
	//�Ƚ����Ŀγ̳ɼ�
    for(int i=0; i<=2; i++)
    {
        int sum = 0;         //ע�����ÿ�ζ�����ˢ���˱���
        int maxScore = -1;   //���һ�����õ�һ���ɼ���Ϊ���ɼ�
        int maxIndex = -1;
        for(int j=0; j<=4; j++)
        {
            int score = student[i].scores[j];  //���δ���
            sum = sum + score;  //��ʹ���
            if(score>maxScore)   //�����������������ֵ
            {
                maxScore = score;  //�Ƚϴ�С������Ϊ���ҳ����������±�
                maxIndex = j;    //���ſγ̵ĵڼ���
            }
        }
        cout<<"Student "<<i+1<<" : ave = "<<sum/5.0<<" , maxCourse = "<<course[maxIndex].getname()<<endl;
    }
	
	//�Ƚ���õ�ѧ���ɼ�
	int temScore[5]=0;   //ע�����û��ˢ�±���
	int maxscore[5] = {0}; //������ſγ̵����ɼ�
	int maxStuIndex[5] = {0};
	for(int i=0;i<=2;i++)
	{
		for(int n=0;n<=4;n++)
		{
			int score = student[i].score[n];  //�������������
			temScore[i] = temScore[i] + score;  //����ѧ���ĳɼ���
			if(score>=maxScore[n])
			{
				maxScore[n] = score;
				maxStuIndex[n] = i;   //���ɣ���
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

