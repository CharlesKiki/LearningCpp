/*
	文件内容：二元数组的内存模型。

*/

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void main2()
{
	int i = 0;

	//指针数组
	/*
		Commit：注意，这个数组内的每个元素意义上指代一个指针。不是整形数
	*/
	char *   p1[] = {"123", "456", "789"};


	//二维数组
	/*
		Commit：在二维数组中，每个元素的意义由它的数据类型决定
		这有可能也是指针的二维数组
	*/
	char p2[3][4]  = {"123", "456", "789"};

	//等价的二维数组形式
	/*
		Commit：
			1.注意，这个操作等价于声明了一个长度为4的一维数组
			int array[3];
			2.二维指针：
	*/
	char **p3 = (char **)malloc(3 * sizeof(char *)); 

	for (i=0; i<3; i++)
	{
		/*
			Commit：该句子的含义是针对指定的内存地址开始，分配 连续的 不连续的 指定长度内存
		*/
		p3[i] = (char *)malloc(10*sizeof(char)); //char buf[10]

		sprintf(p3[i], "%d%d%d", i, i, i);
	}
}


void main555()
{
	printf("hello...\n");
	system("pause");
	return ;
}