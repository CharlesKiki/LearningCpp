#include   <stdio.h> // �������Ծ������ո� ��һ�������ǰ��ʮ�����ֺ�
//old-style parameter declarations in prototyped function definition| ��������ʱҪ����ֺ�
void squares(void);
int main (void)  //��main������������������Ҫʹ�÷ֺ�
{
    int count , sum ;
    count=0;
    sum=0;
    while(count++<20)  //С�ںźͲ�������һ��
        sum = sum +count;
        printf("sun = %d",sum);



}
//���� ++
//���ڳ��Լ�������һ������
void squares(void)
{
    int num =1;
    while (num<21);
    {
        printf("%4d %6d\n",num,num *num);
        num = num +1;
    }
    return 0;
}
