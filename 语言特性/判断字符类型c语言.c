#include <stdio.h>
#include <stdlib.h>
void main(     )
{

  printf("��������һ���ַ���");
     char ch = getchar();
		if(ch>= 'a'&&ch<= 'z')
		printf("���ַ���Сд��ĸ");  //ע�⣬charҲ��һ���������ͣ����洢�����ַ���asciiֵ
		else if(ch >= 'A'&&ch <='Z')
		printf("���ַ��Ǵ�д��ĸ");
		else if(ch>='0'&&ch <='9')
		printf("���ַ�������");
		else
		printf("���ַ��������ַ�") ;
		printf("\n") ;
		system("pause");
}
