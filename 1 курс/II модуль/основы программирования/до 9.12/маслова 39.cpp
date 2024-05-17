//Maslova Anastasia, RUDN, NKNbd-01-21, 17.11.21, 12:04
#include <stdio.h>
#include <iostream>
//39. Дано четырехзначное число. Определить, кратна ли трем сумма его цифр.
int main(){
    int a,b,c,d,temp;
    printf("Программа определяет, делится ли сумма цифр данного четырехзначного числа на 3. \n");
    do{
        printf("Введите четырехзначное число: ");
        scanf("%i",&temp);
    }while(temp<1000 || temp>9999);
    a=temp/1000;
    b=(temp-a)/100;
    c=(temp-a-b)/10;
    d=(temp-a-b-c)/1;
    if ((a+b+c+d)%3==0)
        printf("Сумма цифр данного числа делится на 3.");
    else printf("Сумма цифр данного числа не делится на 3.");
return 0;
}
