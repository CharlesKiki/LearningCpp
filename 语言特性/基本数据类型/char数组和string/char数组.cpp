#include<stdlib.h>　	
#include<stdio.h>
int main()
{
	char ch1[] = "give me";
　　char ch2[] = "a cup";
	/*
		commit:第二个参数复制到第一个参数中
	*/
　　strcpy(ch1,ch2);
　　cout<<"ch1="<<ch1<<endl;
	return 0;
}