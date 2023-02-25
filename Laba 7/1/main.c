#include <stdio.h>

enum Lamps {
    Halogen,
    Daylight,
    Incandescent,
    MetalHalide,
    Fluorescent,
    LED};

int main() {
    enum Lamps a,b,c,d,e,f;
    a=Halogen;
    b=Daylight;
    c=Incandescent;
    d=MetalHalide;
    e=Fluorescent;
    f=LED;
    printf("%d", a);}
