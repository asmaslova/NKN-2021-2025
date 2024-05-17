//Maslova Anastasia, 08.12.2021, RUDN, NKNbd-01-21
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x;
    float y;
    cout<<"Программа выводит первое значение y=sin x, sin sin x, ..., меньшее по модулю 10^(-4).\n";
    do{cout<<"Введите x, не равные 1 и 0: ";
    cin>>x;
    }while(x==1 || x==0);
    y=sin(x);
    do{
        y=sin(y);
    }while(abs(y)>0.0001);
    cout<<y;
    return 0;
}

