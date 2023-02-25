#include <stdio.h>
#include <stdlib.h>

enum{ON=0b0001, SDisON=0b0010, CompactFlashisON=0b0010, MemoyStickisON=0b0100};

int main() {
    unsigned char a;
    scanf("%i", &a);
    if (a & ON)
        printf("\nCard-reader is on");
    if (a & SDisON)
        printf("\n""SD is on ");
    if (a & CompactFlashisON)
        printf("\nCompact Flash is on ");
    if (a & MemoyStickisON)
        printf("\nMemoy Stick is on");
    return 0;
}
