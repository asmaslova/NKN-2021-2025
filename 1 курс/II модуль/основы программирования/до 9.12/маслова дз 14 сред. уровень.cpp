/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Maslova Anastasia, 05.12.21, RUDN, NKNbd-01-21//
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x, N, s;
    int a;
    cout<<"Программа для вычисления приближенного значения функции ln в точке х+1 при вводе х и N.\n";
    do{
        cout<<"Введите х и N через пробел: ";
        cin>>x>>N;
    }while(N<=0);    
    a = 1;
    s = 0;
    do{
        s = s + ((pow((-1),(a+(-1))))*((pow(x,a))/a));
        a++;
    }while (a!=(N+1));
    cout<<"Приблизительное значение функции: "<<s;
    return 0;
}


