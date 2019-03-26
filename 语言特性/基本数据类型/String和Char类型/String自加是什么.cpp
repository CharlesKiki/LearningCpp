#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int main() {
	string ch = "原字符串。";
	ch += "新增加的字符串。";
	cout << "自加的效果：" << ch << endl;
	/*
		ch += "新增加的字符串。"; == ch = ch + "新增加的字符串。";
		原字符串在前，新增字符串在后。
	*/
	system("pause");
	return 0;
}
