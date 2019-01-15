#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>　	
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	/*
		功能：赋值
	*/
	string str1 = "give me";
　　string str2 = "a cup";
　　str1 = str2;
　　cout<<"str1="<<str1<<endl;
　　str1.assign(str2,0,5);       // 参数2为起始位置，参数3为字符数
　　cout<<"str1="<<str1<<endl;
	system("pause");
	return 0;
}