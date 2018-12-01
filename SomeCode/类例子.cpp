//==========================没有严格按照工程要求的类====================================

class StudentClass
{
public:
    void SetID(int i)
    {
        SID = i;
    }
    void SetName(char *Name)
    {
        strcpy(name,Name);
    }
    void SetScore(int i,int s)
    {
        scores[i] = s;
    }
    int GetScore(int i)
    {
        return scores[i];
    }
    char* GetName()
    {
        return name;
    }

private:
    int SID;
    char name[20];
    int scores[5];
};

int main0523()
{
    //Step1, define variables
    StudentClass s[3];

    //Step2, input
    int id = 0 , score = 0;
    char name[20] = {0};
    for(int i=0; i<=2; i++)
    {
        cout<<"Input the ID, name and 5 scores of the student "<<i+1<<" : ";
        //cin>>s[i].SID>>s[i].name;
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
    int maxStuScore[5] = {0};
    int maxStuIndex[5] = {0};
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            int score = s[i].GetScore(j) ;// s[i].scores[j];
            if(score>maxStuScore[j])
            {
                maxStuScore[j] = score;
                maxStuIndex[j] = i;
            }
        }
    }
    for(int i=0; i<=4; i++)
    {
        int index = maxStuIndex[i];
        cout<<"Course "<<i+1<<" : maxStudent = "<<s[index].GetName()<<endl;;
    }


    return 0;
}

//================================================================================

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
        cout<<"Input the ID, name and 5 scores of the student "<<i+1<<" : ";
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
        int sAve = 0;
        for(int j=0; j<=4; j++)
        {
            sAve = sAve + s[i].scores[j];
        }
        cout<<"The average score of student "<<i+1<<" is "<<(sAve/5.0)<<endl;
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
    for(int i=0; i<=4; i++)
    {
        cout<<"The average score of course "<<i+1<<" is "<<a[i]/3.0<<endl;
    }


    return 0;
}

