#include<iostream>
using namespace std;
int 1main()
{
    int x,y,z,count=0;//x����yĸ��zС��
    cout<<"��Ǯ��ټ��Ŀ������У�"<<endl;
    for(x=0;x<=20;x++)
        for(y=0;y<=33;y++)
            for(z=0;z<=300;z=z+3)
             if(5*x+3*y+z/3==100&&x+y+z==100)
             {
                 ++count;
                 cout<<count<<":"<<x<<","<<y<<","<<z<<endl;
             }

}
