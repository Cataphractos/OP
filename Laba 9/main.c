#include <stdio.h>

int main() {
    char string[5];
    int chislo = 12345;
    sprintf(string,"%d",chislo);



    int value;
    printf("enter the amount");
    scanf("%d", &value);
    int time;
    printf("enter the number of months");
    scanf("%d", &time);
    int history[time];
    int st;
    printf("enter the percentage");
    scanf("%d", &st);
    int add;

    int counter;
    history[0]=value;
    counter=1;
   do
    {
        add=history[counter-1] * st /100;
        history[counter]=add+history[counter-1];
        counter++;
    }
   while (counter != 5);




   counter=0;
   do
    {
        printf(" %d", history[counter]);
        counter++;
    }
    while (counter != 5);






}
