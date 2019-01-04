#include <stdio.h> 
#include <stdlib.h>
int g1=0, g2=0, g3=0; 
int main() 
{ 
    static int s1=0, s2=0, s3=0; 
    int v1=0, v2=0, v3=0; 
    //打印出各个变量的内存地址 
	printf("Print the address of local variavle \n");
    printf("0x%08x\n",&v1);
    printf("0x%08x\n",&v2); 
    printf("0x%08x\n\n",&v3); 
	
	printf("Print the address of global variavle\n");
    printf("0x%08x\n",&g1);
    printf("0x%08x\n",&g2); 
    printf("0x%08x\n\n",&g3); 
	
	printf("Print the address of static variavle\n");
    printf("0x%08x\n",&s1);
    printf("0x%08x\n",&s2); 
    printf("0x%08x\n\n",&s3); 
	system("PAUSE");
    return 0; 
}