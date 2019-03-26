//注意一个细节：位运算必须建立在int类型上
#include<stdio.h>
 
int main(void)
{
  unsigned char c=0xfc;
  //关于关键字 unsigned cha 使用补码存储r
  //int/long/short默认为signed  符号类型 无符号类型
  unsigned int i=~c;
  //无符号类型的int，~取反符号
  printf("0x%x\n",i);
  return 0;
}
//异或运算的特性
// a^0=a，a^a=0 
#include<stdio.h>
 
int main(void)
{
  //这个方法只能运用在整数上
  int a=3;
  int b=2;
  a=a^b;
  b=a^b;
  a=a^b;
  printf("%d %d\n",a,b);
  //第二种方法也可以不借助额外的变量，这个方法还可能在造成溢出
  a=a+b;

  b=a-b;

  a=a-b;
  return 0;
}
