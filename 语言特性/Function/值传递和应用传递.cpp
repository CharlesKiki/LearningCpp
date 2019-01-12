#include <iostream>
using namespace std;
 
class MyClass
{
public:
    MyClass(double x,double y) { x = count,y = value; }
    MyClass() { count = 0, value = 0; }
    double tripleByValue(double);
    double tripleByReference(double &);
    void setvalue();
private:
    double count;
    double value;
};
 
 
void MyClass::setvalue()
{
    cout << "输入一个数并计算立方" <<endl;
    cin>>count;
}
 
double MyClass::tripleByValue(double m_count)
{ 
    value=count*count*count;
    return value;
}
 
double MyClass::tripleByReference(double &count)
{
    value= count*count*count;
    return value;
}
 
int main(void)
{
    MyClass a;
    a.setvalue();
    cout << "按值传递的value为：" << endl;
    a.tripleByValue(1.1);
    cout << "按引用传递的value为：" << endl;
    double b = 1.2;
    a.tripleByReference(b);
  
    return 0;
 
}