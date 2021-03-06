/*二进制方式读取数据*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp_r, *fp_w;
    fp_r = fopen("G://timg.jpg", "rb"); //打开图片文件
    fp_w = fopen("G://img.jpg", "wb");  //创建图片文件
    if (fp_r == NULL)
    {
        puts("原始图片打开失败！\n");
        exit(0);
    }
    if (fp_w == NULL)
    {
        puts("文件2打开失败！\n");
        exit(0);
    }
    puts("两个文件打开成功!\n");
    char ch;
    int i = fread(&ch, 1, 1, fp_r); //以二进制方式读取图片
    while (i != 0)
    {
        fwrite(&ch, 1, 1, fp_w); //以二进制方式写入
        i = fread(&ch, 1, 1, fp_r);
    }
    int return_value = fclose(fp_r);
    if (return_value != 0)
    {
        puts("关闭原始图片失败!\n");
        exit(0);
    }
    return_value = fclose(fp_w);
    if (return_value != 0)
    {
        puts("关闭文件2失败!\n");
        exit(0);
    }
    puts("两个图片都关闭成功！\n");
    return 0;
}
