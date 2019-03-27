#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;

int main()
{
    int i;
    cout << typeid(cin >> i).name() << endl;
    system("PAUSE");
    return 0;
}
//typeid获得运行时的类型，typeid(...).name()就是用字符串(char*型)来表示这个类型。
//class std::basic_istream<char,struct std::char_traits<char> >