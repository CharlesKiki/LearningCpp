#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//在当前目录创建txt文件
char c;
int main() {
	int number = 9;
	char number2 = '9';
	FILE*fp = NULL;//文件指针初始化
	fp = fopen("./Test.txt", "w");  //创建文件
	if (NULL == fp) return -1;//要返回错误代码
	fprintf(fp, "%c", number2);
	fprintf(fp, "%d", number);
	fclose(fp);
	fp = NULL;//需要指向空，否则会指向原打开文件地址    
	return 0;
}

/*
	实验结果：最后写入的值都为39，表示为ASCII了。
*/