/*
	功能：函数指针
*/
#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
	return (x > y ? x : y);
}

int main()
{
	int (*ptr)(int, int);
	int a, b, c;

	ptr = max;
	scanf("%d%d", &a, &b);

	c = (*ptr)(a, b);
	printf("a=%d,b=%d,max=%d", a, b, c);
	system("PAUSE");
	return 0;
}