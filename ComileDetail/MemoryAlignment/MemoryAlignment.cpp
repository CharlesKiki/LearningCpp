	/*
		程序功能：检查数据类型占用的空间大小。
		结构体类型在内存中因为内存对齐的大小。
	
	*/
#include <stdio.h>
#include <stdlib.h>
struct SizeStruct{
    char a;
    int b;
    short c;
};
int main(){
	/*
	实验结果：
	char: 1 byte
	int: 4 byte 
	short: 2 byte
	Struct: 12 byte 
	*/
	char Sizechar = 'a';
	int Sizeint = 10;
	short Sizeshort = 0;
	struct SizeStruct Struct;
	/*打印占用空间大小*/
	printf("char: %ld\n", sizeof(Sizechar));
	printf("int: %ld\n", sizeof(Sizeint));
	printf("short: %ld\n", sizeof(Sizeshort));
    printf("Struct: %ld\n", sizeof(Struct));
	/*打印内存位置*/
	printf("char: %p\n", &Sizechar);
	printf("int: %p\n", &Sizeint);
	printf("short: %p\n", &Sizeshort);
    printf("Struct: %p\n", &Struct);
	system("PAUSE");
    return 0;
}