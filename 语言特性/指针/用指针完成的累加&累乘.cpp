#include <iostream>

using namespace std;

void Mix(int Num,int *Sum,long long *Total) // 所以传入的只能是地址类型0
{
    *Total=1;
    for (int num=1;num<=Num;num++)
    {
        *Total=*Total*num;
    }
//------------------分割线-----------------
    *Sum=0;
    int num=1;
	while(num<=Num)
	{
		*Sum=*Sum+num;
		num++;
	}
}

int main()
{
	int out1=0;  //指向累加和
	long long out2=0;  //指向阶乘
    for(int Number=1;Number<=10;Number++)
    {
        Mix(Number,&out1,&out2);
		cout<<"The number is"<<Number<<endl;
		cout<<"The sum is "<<out1<<endl;
		cout<<"The Factorial is"<<out2<<endl;
		cout<<"-----------------------------"<<endl;
    }
    return 0;
}
