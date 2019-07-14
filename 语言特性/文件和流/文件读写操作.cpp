//42 1610242852 15°à ÕÅ¿¡×æ
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int num;
    int sum;
    num=sum=0;
    ofstream fout("data.txt",ios::app);
    while(1)
    {
        num=0;
        cin>>num;
        fout<<num<<endl;
        if(num==0)
            break;
    }
    fout.close();
    ifstream fin("data.txt");
    while(fin>>num)
    {
        sum=sum+num;
    }
    fin.close();
    cout<<"The sum is "<<sum<<endl;
    return 0;
}

int main()
{
    //Step1, input several integers and write them into the file
    char fileName[20] = "data.txt";
    ofstream fout(fileName);//open the file
    int data;
    while(cin>>data)//input data from the keyboard
    {
        if(data==0)//if the input data is 0, exit the loop
        {
            break;
        }
        fout<<data<<endl;//write the data into the file
    }
    fout.close();//close the file

    //Step2, read data from the file and output their summary
    ifstream fin(fileName);//open the file
    int sum = 0;
    while(fin>>data)//read a data from the file
    {
        sum = sum + data;//summary
    }
    fin.close();//close the file

    cout<<"The summary is "<<sum<<endl;


    return 0;
}
