#include <iostream>

using namespace std;

void Mix(int Num)
{
    cout<<Num<<"½×³Ë"<<endl;
    long long Total=1;
    for (int num=1;num<=Num;num++)
    {
        Total=Total*num;
        cout<<Total<<endl;
    }
    cout<<Num<<"ÀÛ¼Ó"<<endl;
    int Sum=0;
    int num=1;
	while(num<=Num)
	{
		Sum=Sum+num;
		num++;
		cout<<Sum<<endl;
	}
    cout<<"----------------"<<endl;
}

int main()
{
    int Number;
    for(Number=1;Number<=10;Number++)
    {
        Mix(Number);
    }
    return 0;
}
