//Maslova Anastasia 07.12.2021
#include <locale.h> //для исправления кодировки, чтобы русский текст нормально выдавался
#include <iostream> //classics
#include <math.h> //математическая библиотека (степени, тригонометрия и все такое)
using namespace std; //чтобы использовать cin и cout вместо printf и прочего
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, n, s; //a - дано, n = сотни, s - результат деления
    cout << "Программа выводит результат деление нечетных сотен на заданное число А. \n";
    do {
        cout << "Введите число А от 1 до 1000: ";
        cin >> a;
    } while (a>1000 || a<1);
    do {
        if (a < n)
            s = n \ a;
        cout << n << " : " << a << " = " << s;
        else break;
        n = n + 200
    } while (n != 1100);
    return 0
}