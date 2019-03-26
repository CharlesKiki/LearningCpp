#include <stdio.h>
#include <stdlib.h>
void main(     )
{

  printf("请数输入一个字符：");
     char ch = getchar();
		if(ch>= 'a'&&ch<= 'z')
		printf("该字符是小写字母");  //注意，char也是一种整型类型，它存储的是字符的ascii值
		else if(ch >= 'A'&&ch <='Z')
		printf("该字符是大写字母");
		else if(ch>='0'&&ch <='9')
		printf("该字符是数字");
		else
		printf("该字符是其他字符") ;
		printf("\n") ;
		system("pause");
}
