#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int main() {
    printf ("enter the first string");
    char message[5];
    scanf("%4s", message);
    puts(message);

    printf ("enter the second string");
    char string[5];
    scanf("%4s", string);
    puts(string);

    if (strcmp ( message, string )==0)
        puts("identical");
    else
        puts("different");

    int *any;
    any = strpbrk(message, string);
    printf ("symbol found %c\n", *any);

    int length;
    length = strspn(message, string);
    printf ("length %d\n", length);


    int counter=0;
    int place=0;
    printf ("enter the symbol");
    char search[1];
    scanf("%1s", search);
    while (counter<6)
    {
        if (message[counter] == search[0]){
            printf ("place is %i\n", counter);
            break;
        }
        else
            counter++;
    }


    puts(strcat(message, string));





    return 0;
}

