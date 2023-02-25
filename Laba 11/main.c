#include <stdio.h>
#include <math.h>

struct figure{
    int kat1;
    int kat2;
    double gip;
    int S;
};

int main() {
    struct figure triangle={};
    printf("Enter kat1");
    scanf("%d", &triangle.kat1);
    printf("Enter kat2");
    scanf("%d", &triangle.kat2);
    triangle.gip= sqrt(triangle.kat1*triangle.kat1+triangle.kat2*triangle.kat2);
    triangle.S=triangle.kat1*triangle.kat2/2;

    printf("Gip:%f\nS:%d", triangle.gip, triangle.S);
    return 0;
}
