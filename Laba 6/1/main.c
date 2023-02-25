#include <stdio.h>

int main() {
    int i;
    i=3;
    int array[5]={1000,1001,1002,1003};
    int *link1 = &array[0];
    int *link2 = &array[1];
    int *link3 = &array[2];
    int *link4 = &array[3];
    int *link5 = &array[4];
    int links[5]={*link1,*link2,*link3,*link4,*link5,};
    while (i>=0){
        printf ("Adress[%p], %d\n", i, links[i]);
        i--;
    }
}
