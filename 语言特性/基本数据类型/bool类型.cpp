/*
C++中的布尔类型
    C++在C语言的基本类型系统之上增加了bool
    C++中的bool可取的值只有true和false
    理论上bool只占用一个字节，
    如果多个bool变量定义在一起，可能会各占一个bit，这取决于编译器的实现

    true代表真值，编译器内部用1来表示
    false代表非真值，编译器内部用0来表示

    bool类型只有true（非0）和false（0）两个值
    C++编译器会在赋值时将非0值转换为true，0值转换为false
*/
int main(int argc, char *argv[])
{
    int a;
    bool b = true;
    printf("b = %d, sizeof(b) = %d\n", b, sizeof(b));

    b = 4;
    a = b;
    printf("a = %d, b = %d\n", a, b);

    b = -4;
    a = b;
    printf("a = %d, b = %d\n", a, b);

    a = 10;
    b = a;
    printf("a = %d, b = %d\n", a, b);

    b = 0;
    printf("b = %d\n", b);

    system("pause");
    return 0;
}