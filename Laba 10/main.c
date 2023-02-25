#include <stdio.h>

int main() {
    char string[10];
    char result[10];
    int counter;
    int counter1;

    printf("Enter the string\n");
    gets(string);


    counter = 0;
    counter1=0;

    while (counter != 10) {
        if (string[counter] != ' ') {
            result[counter1] = string[counter];
            counter++;
            counter1++;
        }
        if (string[counter] == ' '){
            counter++;}
    }

    puts(result);

}