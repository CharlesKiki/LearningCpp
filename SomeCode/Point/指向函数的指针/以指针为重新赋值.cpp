#include<stdio.h>
#include<stdlib.h>

void FileFunc()
{
printf("FileFunc\n");
}

void EditFunc()
{
printf("EditFunc\n");
}

int main()
{
	typedef void (*funcp)();
	/*
		comiit：相当于给指针赋值。
	*/
	funcp pfun= FileFunc;
	pfun();
	pfun = EditFunc;
	pfun();
	system("PAUSE");
	return 0;
}