//42 1610242852 15 张俊祖
#include <iostream>

using namespace std;

int main()
{
	double Num[10];
	double num; //一个间接变量，没有实际意义
	double Ave,max,min,Total;
	Total=0;
    for(int i=0;i<=9;i++)
    {
        cin>>num;
        Num[i]=num;
    }
	for(int i=0;i<=9;i++)
	{
		Total=Num[i]+Total;
	}
	Ave=Total/10;
	for(int i=1;i<=9;i++)
	{
	    max=Num[0];
	    min=Num[0];
		if(max<Num[i])
		{
			max=Num[i];
		}
		if(min>Num[i])
		{
			min=Num[i];
		}
	}
    cout<<"The Average is "<<Ave<<endl;
    cout<<"The large is "<<max<<endl;
    cout<<"The small is "<<min<<endl;
}


