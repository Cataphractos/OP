#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int c = a>=-56 & a<=56;
    printf("%d", c);
    int f;
    int result;
    int check=0b0000001;
    scanf("%d", &f);
    result= f & check;
    printf("%d", result);
}
