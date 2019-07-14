/*
	文件功能：int类型和char类型写入文件中是什么内容？
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

char c;
int main() {
	int number = 9;					//int类型存储数字
	char number2 = '9';				//字符类型存储数字

	FILE*fp = NULL;					//文件指针初始化
	fp = fopen("./Test.txt", "w");  //创建文件
	if (NULL == fp) return -1;		//返回错误代码

	fprintf(fp, "%c", number2);
	fprintf(fp, "%d", number);
	fclose(fp);
	fp = NULL;						//需要指向空，否则会指向原打开文件地址    

	return 0;
}

/*
	实验结果：char类型写入的9为ASCII值。
*/