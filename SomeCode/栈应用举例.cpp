#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> S;
	for(int i=1;i<=6;i++) S.push(i);//进栈123456
	while(!S.empty()){
		cout<<S.top()<<" ";S.pop();//出栈 654321
	}
	return 0;
}

//注意C++的变成格式问题
//栈存在空和非空两个状态empty()检测
//定义栈类型 stack<type> name相当于类型操作
