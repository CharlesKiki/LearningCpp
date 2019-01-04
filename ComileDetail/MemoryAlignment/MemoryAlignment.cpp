#include <stdio.h>
#include <stdlib.h>
struct A{
    char a;
    int b;
    short c;
};
int main(){
    struct A a;
    printf("A: %ld\n", sizeof(a));
	system("PAUSE");
    return 0;
}