// count the girth and area of circle
#include<iostream.h>
using name std;
void main ()
{ double r, girth, area ; 		
   const double PI = 3.1415 ;
   cout << "Please input radius:\n" ; //操作符重载
   cin >> r ;  //输入
   girth = 2 * PI * r ; 
   area = PI * r * r ;
   cout << "radius = " << r << endl ; 
   cout << "girth = " << girth << endl ;
   cout << "area = " << area << endl ;
}