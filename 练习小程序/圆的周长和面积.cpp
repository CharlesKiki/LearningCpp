/* 求圆的周长和面积
数据描述：    
        半径，周长，面积均用实型数表示
数据处理：
        输入半径 r；
        计算周长 = 2*π*r ；
        计算面积 = π* r2 ；
        输出半径，周长，面积；
方法1：用结构化方法编程，求圆的周长和面积 */
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

//方法2：用面向对象方法编程，求圆的周长和面积

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