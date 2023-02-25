#include <stdio.h>

int main() {
    char *filename1 = "data.txt";
    char *filename2= "data2.txt";
    char *filename3 = "New.txt";
    char buff [256];
    FILE *f1 = fopen("data.txt", "r");
    FILE *f2 = fopen("data2.txt", "r");
    FILE *fend = fopen("New.txt", "w+");
    while((fgets(buff, 256, f1))!=NULL)
    {
        fputs(buff, fend);
        printf("%s", buff);
    };
    while((fgets(buff, 256, f2))!=NULL)
    {
        fputs(buff, fend);
        printf("%s", buff);
    }
}
