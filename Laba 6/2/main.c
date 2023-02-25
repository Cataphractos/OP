#include <stdio.h>

int main() {
    int i;
    i=3;
    int *array=NULL;
    array= malloc(sizeof(int)*2);
    *array=1000;
    *(array+1)=1001;
    *(array+2)=1002;
    *(array+3)=1003;
    while (i>=0){
        printf ("Adress[%p], %d\n", array+i, array[i]);
        i--;}
    free(array);
    array=NULL;
    return 0;
}