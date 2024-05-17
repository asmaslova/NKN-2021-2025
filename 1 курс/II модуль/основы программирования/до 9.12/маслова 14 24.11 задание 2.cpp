/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Maslova Anastasia, RUDN, NKNbd-01-21, 24.11.21, 13:37
#include <stdio.h>
#include <cmath>
//Дана последовательность а(n)=√(n^2+1), n=1,2,... Составить алгоритм и программу вычисления и вывода членов последовательности начиная с а(10) и заканчивая а(20).

int main()
{
    int n;
    float a;
    printf("Программа вычисления и вывода членов последовательности начиная с а(10) и заканчивая а(20)\n");
    printf("для последовательности а(n)=√(n^2+1), n=1,2,...\n");
    n=10;
    while (n!=21){
        a=sqrt(n*n+1);
        printf("%f ",a );
        n=n+1;
    }
return 0;    
}


