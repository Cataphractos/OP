#include <stdio.h>

struct triangle{
    int side1;
    int side2;
    int side3;
};

int main() {
    struct triangle object={4,5,6};
    int p;
    p=object.side1+object.side2+object.side3;
    printf ("%d", p);}
