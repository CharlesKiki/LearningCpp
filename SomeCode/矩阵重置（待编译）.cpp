//42 1610242852 15 ÕÅ¿¡×æ
#include <iostream>

using namespace std;

int main()
{
    int Matrix[3][3]={0};
	int NewMatrix[3][3]={0};
    for(int n=0;n<=2; n++)
    {
        for(int N=0;N<=2; N++)
        {
            cin>>Matrix[n][N];
        }
    }
    for(int n=0;n<=2; n++)
    {
        for(int N=0;N<=2; N++)
        {
            cout<<Matrix[n][N]<<" ";
        }
        cout<<endl;
    }
/*  This is a bad output
    cout<<Matrix[0][0]<<" "<<Matrix[1][0]<<" "<<Matrix[2][0]<<endl;
    cout<<Matrix[0][1]<<" "<<Matrix[1][1]<<" "<<Matrix[2][1]<<endl;
    cout<<Matrix[0][2]<<" "<<Matrix[1][2]<<" "<<Matrix[2][2]<<endl;
*/
	for(int n=0;n<=2; n++)
    {
        for(int N=0;N<=2; N++)
        {
            NewMatrix[N][n]=Matrix[n][N];
        }
    }
	for(int n=0;n<=2; n++)
    {
        for(int N=0;N<=2; N++)
        {
            cout<<NewMatrix[N][n]<<" ";
        }
        cout<<endl;
    }



    return 0;
}
