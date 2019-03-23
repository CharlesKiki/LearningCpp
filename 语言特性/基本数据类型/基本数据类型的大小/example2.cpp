int main()
{
    int a = 10;
    int b[10];
    printf("int a:%d \n", sizeof(a));
    printf("int a:%d \n", sizeof(int *));
    printf("int b:%d \n", sizeof(b));
    printf("int b:%d \n", sizeof(b[0]));
    printf("int b:%d \n", sizeof(*b));
    printf("hello.....\n");
    getchar();
    return 0;
}