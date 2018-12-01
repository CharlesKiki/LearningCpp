#include <iostream>
using namespace std;

int main()
{
    char a;
    int b;
    float c;
    string 
    cin>>a>>b>>c;
    cout<<a<<" "<<b<<" "<<c<<" "<<endl;

    system("pause");
    return 0;
}

1 cin是标准输入流对象，即istream类的对象，用于从标准输入读取数据  >>流运算符
2 cout是流的对象，即ostream类的对象，cerr是标准错误输出流的对象，也是ostream 类的对象
3 标准输入缓冲区
	1 从键盘输入字符串需要回车键(\r)才能够将字符串送入到缓冲区
	2 (\r)当成一个字符来计算
	3 注意‘123456’字符串，此时缓冲区中的字节个数是7
4 使用方法 
	cin>>，cin.get，cin.getline
5 while(cin>>x){ ......}问题
	>>流运算符问题
	">>"输入操作符接收一个istream对象作为其做操作数，接收一个对象作为其右操作数。
	">>"操作符返回其左操作数作为结果
		cin>>x>>y问题
			cin>>x返回cin对象，接着又可以进行cin>>y。
			何时退出循环问题 CTRL+Z后，按下两次回车，就可以得到结果0000 0000.所以上面的while会退出循环。
6 流结束标志问题 CTRL+Z或者CTRL+D
	ctrl-z 发送 SIGTSTP 信号给前台进程组中的所有进程，常用于挂起一个进程。
	ctrl-d 不是发送信号，而是表示一个特殊的二进制值，表示 EOF(换行符)。
7 阻塞式IO，非阻塞式IO 问题
	1 阻塞式IO：阻塞式IO指的是一旦输入/输出工作没有完成，则程序阻塞，直到输入/输出工作完成。
	2 非阻塞式IO：非阻塞式IO并非完全非阻塞，通过设置超时来读取数据的。
	未超时之前，程序阻塞在读写函数上；超时后，结束本次读取，将已读到的数据返回。
7 非ASCII数据 Ctrl Z产生的不是一个字符，所以不会跟其它从键盘上输入的字符一样能够存放在输入缓冲区。
8 读取数据流和检测数据流结束的问题
	如果输入缓冲区中有可读的数据则不会检测 Ctrl+Z（因为有要读的数据，还不能认为到了流的末尾）。
9 返回值类型问题
	#include <iostream>
	#include <cstdlib>
	#include <typeinfo>
	using namespace std;
	 
	int main()
	{
		int i;
		cout<<typeid(cin>>i).name()<<endl;
		system("PAUSE");
		return 0;
	}
	//typeid获得运行时的类型，typeid(...).name()就是用字符串(char*型)来表示这个类型。
	//class std::basic_istream<char,struct std::char_traits<char> >
	
	