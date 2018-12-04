#include <iostream>

using namespace std;

void Math(int x,int y,int z)
{
    int Sum1=0;
	for(int i=1;i<=x;i=i+1)
	{
	    Sum1=Sum1+i;
	}
	int Sum2=0;
	for(int i=1;i<=y;i++)
    {
        Sum2=Sum2+i*i;
    }
	int Sum3=0;
	for(int i=1;i<=z;i++)
    {
        Sum3=Sum3+i*i*i;
    }
    long long Fin=0;
    long long num=Sum1+Sum2;
    Fin = num / Sum3;
    cout<<Fin;
}
int main()
{
    int x,y,z;
    cout<<"ÇëÊäÈëx,y,z"<<endl;
    cin>>x>>y>>z;
    Math(x,y,z);
    return 0;
}
