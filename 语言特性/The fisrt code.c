#include <stdio.h>
void butler(void);
int main (void)
{
    int num;
    num = 1;
    printf("I am a simple ");
        printf("computer. \n");
            printf("My favorite number is %d because it is first .\n",num);
        butler();

    int num2;
    num2 = 2;
    printf("This is the first time I write code Let me show you the %d",num2);
    return 0;
}
//return o ���������һ�δ���Ĳ�����? �����Զ�ζ���int main(void)
void butler(void)
{
    printf("I will summon the butler function.\n");
    printf("Yes bring me some tea and writeable CD-ROMS.\n");
    //butler();����˼�Ĵ��� �������μ������ �ͻ�����ظ���butler�����

}  //Ϊʲô�����ﲻ�ܼ���return 0
