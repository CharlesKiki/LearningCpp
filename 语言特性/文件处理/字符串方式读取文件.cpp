/*字符串方式读取
char *fgets(char *str,int n,FILE *stream);
str是一个指向字符串的指针，n是读取的字符和字符串结束的标志"\0"
stream是文件指针，指向将被读取数据的文件
*/
//fgets()函数一次从stream所指向的文件中读取n-1个字符，若是读取的字符包含换行符"\n"
//和文件结束标志，那么读取的字符串将在n-1个字符前终止。
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    fp = fopen("G://CTest//new.txt", "r");
    if (fp == NULL)
    {
        puts("can't open the file!");
        exit(0);
    }
    puts("open file success!\n");
    puts("文件内容是：");
    char arr[20] = {0};
    char *p = fgets(arr, 20, fp); //开始以字符串方式读取文件中数据
    while (p != NULL)
    {
        printf("%s", arr);
        p = fgets(arr, 20, fp);
    }
    printf("\n\n");
    int return_value = fclose(fp);
    if (return_value != 0)
    {
        puts("文件关闭失败！\n");
        exit(0);
    }
    puts("文件成功关闭!\n");
    return 0;
}