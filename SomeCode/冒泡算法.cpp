# include <iostream>
using namespace std ;
struct  person	// 结构定义
{  char  name[10] ;  unsigned  int  id;  double  salary ;  } ;
person  allone[6] ;	// 结构数组声明
int main ( )
{  int  i ;   person  temp ;		// 结构变量声明
   for ( i = 0 ;  i < 6 ;  i ++ )	// 输入数据
     { cout << i << ": name: " ; cgets ( allone[i].name ) ;
        cout << "id: " ;     cin >> allone[i].id ;
        cout << "salary: " ;     cin >> allone[i].salary ;
        cout << endl ;
     } ;
cout << "Sort:\n" ;
  for  ( i=1 ;  i < 6 ;  i ++ )		// 以成员salary作关键字排序
  {  for ( int  j = 0 ;  j <= 5-i ;  j ++ )
     { if  ( allone[j].salary > allone[j+1].salary  )     // 结构变量的整体交换 
           {  temp = allone[j] ;    allone[j] = allone[j+1] ;     allone[j+1] = temp ;  }
     }
  }
  for ( i = 0 ;  i < 6 ;  i ++ )		// 输出排序后数据
      cout << allone[i].name << '\t' << allone[i].id << '\t' << allone[i].salary << endl ;
}

//bublle.cpp
void bublle(ing a[],int size)
{
	int i,temp,work;
	for(int pass =1;pass<size;pass++)
	{
		work =1;
		for(i=0;i<size-pass;pass++)
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				work=0;
			}
			if(work)break;
	}
}
