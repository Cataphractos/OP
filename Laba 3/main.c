#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    printf("octal = %o\n", a);
    printf("hexadecimal = %X\n", a);
    printf("%o >> 4 == %d\n", a, a>> 4 );
    printf("%X >> 4 == %d\n", a, a>> 4);
    int b;
    scanf("%X", &b);
    int c;
    c=b^a;
    printf("%d", c);
    return 0;
}

