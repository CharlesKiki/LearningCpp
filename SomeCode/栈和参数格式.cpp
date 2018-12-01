包含在 <stack>头文件中
栈类成员函数原型
bool empty();  //测试是否为空栈
size_type size(); //返回栈长度
// 元素存取 element access
top（）; //返回栈顶元素
void push（const T& x）;//进栈  
void pop（）； 出栈

参数的理解

定义一个常量，声明的同时必须进行初始化。一旦声明，这个值将不能被改变。

这里的T指的是一种数据类型，可以是int、long、doule等基本数据类型，也可以是自己类型的类型class。

const T、const T*、T *const、const T&、const T*& 的区别 

int i = 5;
const int constInt = 10;        //正确
const int constInt2 = i;        //正确
constInt = 20;                  //错误，常量值不可被改变
const int constInt3;            //错误，未被初始化

//未被初始化的变量无法被const 
// constInt2是const 那么是否可以通过修改i来修改constInt2??

const T*
指向常量的指针，不能用于改变其所指向的对象的值。
const int i = 5;
const int i2 = 10;
const int* pInt = &i;           //正确，指向一个const int对象，即i的地址
//*pInt = 10;                   //错误，不能改变其所指缶的对象
pInt = &i2;                     //正确，可以改变pInt指针本身的值,此时pInt指向的是i2的地址
const int* p2 = new int(8);     //正确，指向一个new出来的对象的地址
delete p2;                      //正确
//int* pInt = &i;               //错误，i是const int类型，类型不匹配，不能将const int * 初始化为int *
int nValue = 15;
const int * pConstInt = &nValue;    //正确，可以把int *赋给const int *，但是pConstInt不能改变其所指向对象的值，即nValue
*pConstInt = 40;  

const int* 与int* const的区别
指针本身就是一种对象，把指针定义为常量就是常量指针，也就是int* const的类型，也可以写成int *const，声明时必须初始化。

const int nConstValue = 1;                      //常量对象
const int nConstValue2 = 2;                     //常量对象
const int* pConstValue = &nConstValue;          //指向常量对象的指针
const int* pConstValue2 = &nConstValue2;        //指向常量对象的指针
const int*& rpConstValue = pConstValue;         //指向常量对象的指针的引用
//*rpConstValue = 10;                           //错误，rpConstValue指向的是常量对象，常量对象的值不可改变
rpConstValue = pConstValue2;                    //正确，此时pConstValue的值等于pConstValue2
//指向常量对象的指针本身是对象，引用可以改变邦定对象的值

int nValue = 5;
int nValue2 = 10;
int *const constPoint = &nValue;                //常量指针
int *const constPoint2 = &nValue2;              //常量指针
int *const &rpConstPoint = constPoint;          //对常量指针的引用,邦定constPoint
//rpConstPoint = constPoint2;                   //错误，constPoint是常量指针，指针本身的值不可改变
*rpConstPoint = 20;                             //正确，指针指向的对象可以改变


