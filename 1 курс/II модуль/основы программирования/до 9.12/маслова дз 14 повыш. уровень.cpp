/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Maslova Anastasia, RUDN, NKNbd-01-21, 05.12.21
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int i,n,k;
    float r,s,p,x;
    cout<<"Программа для вычисления сложной функции при вводе х и n (см. пункт 14, стр. 40).\n";
    cout<<"Примечание! n может быть только натуральным числом больше 3.\n";
    do{
    cout<<"Введите x и n через пробел: ";
    cin>>x>>n;
    }while(n<3);
    k=3;
    i=1;
    r=0;
    p=1;
    do{
        s = (pow((-2),(k+(-1))))/((k-5)*pow(x,k));
        do{
            p=p*(pow(i,3)-(27))/(i-(7));
            i++;
        }while(i!=(k+(7)));
        r = r+(s*p);
        k++;
    }while(k!=(n+(1)));
    cout<<"Ответ: "<<r;

    return 0;
}
//Примечание. Я проверила, и моя программа в теории работает так, как указано в задании, но на практике
//в самом задании, кажется, неточность. Оно не учитывает того, что числитель и знаменатель в произведениях могут быть нулями, 
//из-за чего ответ при любых переменных будет неопределен (nan). Что с этим делать я не знаю. 

