/*读取数据,以字符为单位一个一个从文本文件读取数据,使用库函数fgetc()
int fgetc(FILE *stream);
参数stream是一个文件指针，这个函数如果字符读取成功，返回这个字符的ASCII值，失败返回-1
*/
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
    char ch = fgetc(fp);
    while (ch != -1)
    {
        putchar(ch); //这里还可以用fputc(ch,stdout);把屏幕看作一个文件，stdout就是指向这个文件的指针
                     //fgetc()从文件读取到的字符，依次被字符变量ch指代，可以用putchar()输出，也可以
        //用stdout指针写入到屏幕这个文件中
        ch = fgetc(fp);
    }
    puts("\n");
    int return_value = fclose(fp);
    if (return_value != 0)
    {
        puts("关闭文件失败！\n");
        exit(0);
    }
    puts("文件成功关闭!\n");
    return 0;
}



