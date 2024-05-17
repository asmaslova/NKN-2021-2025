//Maslova Anastasia 07.12.2021, NKNbd-01-21, RUDN
#include <iostream> //classics
#include <math.h> //математическая библиотека (степени, тригонометрия и все такое)
using namespace std; 
int main()
{
    int a, n, s;
    cout << "Программа выводит результат целочисленного деления нечетных сотен на заданное число А. \n";
    do {
        cout << "Введите число А от 1 до 1000: ";
        cin >> a;
    } while (a>1000 || a<1);
    n=100;
    do {
        if (a < n) {
            s = n / a;
            cout << n << " : " << a << " = " << s << endl;
        }
    n = n + 200;
    } while (n != 1100);
    return 0;
}