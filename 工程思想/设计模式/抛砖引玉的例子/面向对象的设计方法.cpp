#include<iostream.h> 
using name std;
class Circle
{  double radius ; //成员变量
  public : //类的访问控制
    void Set_Radius( double r ) { radius = r ; } //成员函数
    double Get_Radius()  { return  radius ; } //通过成员函数设置成员变量
    double Get_Girth()     { return  2 * 3.14f * radius ; } //通过成员函数获取成员变量
    double Get_Area()     { return  3.14f * radius * radius ; }
} ;
void main()
{ 
Circle A, B ; //用类定义对象
   A.Set_Radius( 6.23 ) ; //类的调用
   cout << "A.Radius = " << A.Get_Radius() << endl ;
      cout << "A.Girth = " << A.Get_Girth() << endl ;
   cout << "A.Area = " << A.Get_Area() << endl ;
   B.Set_Radius( 10.5 ) ;
   cout << "B.radius = " << B.Get_Radius() << endl ;
   cout << "B.Girth=" << B.Get_Girth() << endl ;
   cout << "B.Area = " << B.Get_Area() << endl ; 
}