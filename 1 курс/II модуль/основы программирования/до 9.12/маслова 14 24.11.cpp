/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Maslova Anastasia, RUDN, NKNbd-01-21, 24.11.21, 12:23
#include <iostream>
#include <stdio.h>
//Вывести те цифры, которые при делении на b дают в остатке c (b>c>=0)
int main(){
    int a,b,c,d,e;
    printf("Программа, которая при вводе числе а выводит только те цифры, которые при делении на b дает в остатке с.\n");
    do{
        printf("Введите a,b и c: ");
        scanf("%i%i%i",&a,&b,&c);
    }while (b<c || b<0 || c<0);
    while(a!=0){
        e=a%10;
        d = e%b;
        a=a/10;
        if (d == c)
            printf("%i ",e);
    }    
return 0;
}    