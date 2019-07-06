/* 
char *p = “abcdefg”;
Char *buf = “abcdefg”;
一维字符串内存模型：两种 
*/

//复制字符串
//这需要两个字符串长度相同吗
//如果to字符串的长度不够会怎么样，访问到非法的内存吗
void copy_str01(char *from, char *to)
{
    for (; *from!='\0'; from++, to++)
    {
        *to = *from;
    }
    *to = '\0';
}

void copy_str02(char *from, char *to)
{
    while(*from!='\0')
    {
        *to++ = *from++;
    }
    *to = '\0';
}

void copy_str03(char *from, char *to)
{
    while( (*to=*from) !='\0')
    {
        to++;
        from++;
    }
}

void copy_str04(char *from, char *to)
{
    while( (*to++=*from++) !='\0')
    {
        ;
    }
}

int copy_str05_good(const char *from, char *to)
{
    if (from==NULL || to==NULL)
    {
        printf("func copy_str05_good() err. (from==NULL || to==NULL)\n");
        return -1;
    }

    while( (*to++=*from++) !='\0')
    {
        ;
    }
    return 0;
}