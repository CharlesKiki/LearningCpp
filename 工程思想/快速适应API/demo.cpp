/* 
库函数api
*/
int main31()
{
    char buf1[100];
    char buf2[200];
    strcpy(buf1, "111");
    printf("%s", strcat(buf1, "222"));
    getchar();
    return 0;
}

int main32()
{
    char *string1 = "1234567890";
    char *string2 = "747DC8";
    int length;
    //在字符str1中查找，与str2中任意字符有公共交集的位置
    length = strcspn(string1, string2);
    printf("Character where strings intersect is at position %d\n", length);

    getchar();
    return 0;
}

//strnset函数有错误
//测试程序修改如下
int main33()
{
    char string[] = "abcdefghijklmnopqrstuvwxyz";
    char letter = 'x';
    printf("string before strnset: %s\n", string);
    strnset(string, letter, 13);
    printf("string after  strnset: %s\n", string);
    getchar();
    return 0;
}

int main44()
{
    char *string1 = "abcdefghijklmnopqrstuvwxyz";
    char *string2 = "onm";
    char *ptr;
    ptr = strpbrk(string1, string2);
    if (ptr)
        printf("strpbrk found first character: %c\n", *ptr);
    else
        printf("strpbrk didn't find character in set\n");
    getchar();
    return 0;

}

int main55()
{
     char input[16] = "abc,d";
   char *p;
   /* strtok places a NULL terminator
   in front of the token, if found */
   p = strtok(input, ",");
   if (p)   printf("%s\n", p);
   /* A second call to strtok using a NULL
   as the first parameter returns a pointer
   to the character following the token  */
   p = strtok(NULL, ",");
   if (p)   printf("%s\n", p);

    getchar();
    return 0;

}

//典型的状态函数
int main()
{
    char str[] = "now # is the time for all # good men to come to the # aid of their country";
    //char delims[] = "#";
    char *delims = "#";
    char *result = NULL;
    result = strtok( str, delims );
    while( result != NULL ) {
        printf( "result is \"%s\"\n", result );
        result = strtok( NULL, delims );
    }
    printf("----------==========----------\n");
    printf("%s", str);

    getchar();

    return 0;
}