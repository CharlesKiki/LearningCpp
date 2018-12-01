#include <iostream>
#include <cstring> //for strcpy()
#include <fstream> // for ofstream and ifstream

using namespace std;

struct Student
{
    int SID;
    char name[20];
    int scores[5];
};

int main0517()
{
    //Step1, define variables
    char cNames[5][20] = {0};
    Student s[3];

    //Step2, input
    cout<<"Input the names of 5 courses: ";
    for(int i=0; i<=4; i++)
    {
        cin>>cNames[i];
    }
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
    /*
          a[0] a[1] a[2] a[3] a[4]
    s[0] : 11   22   33   44   55
    s[1] : 12   23   34   45   56
    s[2] : 51   62   73   84   95
    */

    //to calculate the average score of each student

    for(int i=0; i<=2; i++)
    {
        int sAve = 0;
        int maxScore = 0;
        int maxIndex = 0;
        for(int j=0; j<=4; j++)
        {
            int score = s[i].scores[j];
            sAve = sAve + score;
            if(score>maxScore)
            {
                maxScore = score;
                maxIndex = j;
            }
        }
        cout<<"Student "<<i+1<<" : ave = "<<(sAve/5.0)<<" , maxCourse = "<<cNames[maxIndex]<<endl;
    }

    //to calculate the average score of each course
    int a[5] = {0};
    int maxStuScore[5] = {0};
    int maxStuIndex[5] = {0};
    for(int i=0; i<=2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            int score = s[i].scores[j];
            a[j] = a[j] + score;
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
        cout<<"Course "<<i+1<<" : ave = "<<a[i]/3.0<<" , maxStudent = "<<s[index].name<<endl;;
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
        cout<<"Input the ID, name and 5 scores of the student "<<i+1<<" : ";
        cin>>s[i].SID>>s[i].name;
        for(int j=0; j<=4; j++)
        {
            cin>>s[i].scores[j];
        }
    }

    //Step3, process and output
    /*
          a[0] a[1] a[2] a[3] a[4]
    s[0] : 11   22   33   44   55
    s[1] : 12   23   34   45   56
    s[2] : 51   62   73   84   95
    */

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
