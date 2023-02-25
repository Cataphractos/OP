#include <stdio.h>

int main() {
    int array[2][2] = {{2,1},{1,3}};
    int array2[2][2] = {{1,3},{2,1}};
    int arrayfinal[2][2];
    arrayfinal[0][0]=array[0][0]*array2[0][0]+array[1][0]*array2[0][1];
    arrayfinal[0][1]=array[0][0]*array2[1][0]+array[1][0]*array2[1][1];
    arrayfinal[1][0]=array[0][1]*array2[0][0]+array[1][1]*array2[0][1];
    arrayfinal[1][1]=array[0][0]*array2[1][0]+array[1][0]*array2[1][1];
    printf("%d ", arrayfinal[0][0]);
    printf("%d\n", arrayfinal[0][1]);
    printf("%d ", arrayfinal[1][0]);
    printf("%d ", arrayfinal[1][1]);
}

