#include<iostream>  //50到100之间的有哪些素数 
using namespace std;
int main()
{
    int a,b;
    int c=0;
    for(a=50;a<=100;a++)
    {
        for(b=1;b<=a;b++)
        {
            if(a%b==0)  
                c=c+1;
        }
        if(c==2)
            cout<<a<<endl;
        c=0;
    }
    return 0;
}
