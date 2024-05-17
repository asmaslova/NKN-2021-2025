//Maslova Anastasia, RUDN, NKNbd-01-21, 10.11.2021, 13:57
#include <stdio.h>
//36. Известен объем и масса тела. Определить плотность материала этого тела.

int main(){
    float v,m,p;
    printf("Программа вычисления плотности тела на основе его объема V и массы m.\n");
    printf("Введите объем V: ");
    scanf("%f",&v);
    printf("Введите массу m: ");
    scanf("%f",&m);
    p = m/v;
    printf("Плотность тела: %f", p);
return 0;
}