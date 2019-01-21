#include <iostream>
 
using namespace std;
class VirtualBase
{
public:
    virtual void Demo() = 0;
    virtual void Fun();
};
void VirtualBase::Fun()
{
    cout<<"父类的Fun执行了"<<endl;
}
class C:public VirtualBase
{
public:
    void Demo();
    void Fun();
};
void C::Demo()
{
 cout << "C::Demo!" << endl;
}
void C::Fun()
{
 cout << "子类C::Fun!" << endl;
}
int main()
{
    cout << "Hello world!" << endl;
    //VirtualBase *p = new VirtualBase();
   // p->Fun();
 //  C c;
  // c.Demo();
 
   VirtualBase *p = new C;
   p->Demo();
   p->Fun();
    return 0;
}