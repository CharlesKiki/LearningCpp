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
//return o 可以造成下一段代码的不运行? 不可以多次定义int main(void)
void butler(void)
{
    printf("I will summon the butler function.\n");
    printf("Yes bring me some tea and writeable CD-ROMS.\n");
    //butler();有意思的错误 如果把这段加入代码 就会造成重复的butler代码块

}  //为什么这这里不能加上return 0
