//Maslova Anastasia 07.12.2021
#include <locale.h> //��� ����������� ���������, ����� ������� ����� ��������� ���������
#include <iostream> //classics
#include <math.h> //�������������� ���������� (�������, ������������� � ��� �����)
using namespace std; //����� ������������ cin � cout ������ printf � �������
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, n, s; //a - ����, n = �����, s - ��������� �������
    cout << "��������� ������� ��������� ������� �������� ����� �� �������� ����� �. \n";
    do {
        cout << "������� ����� � �� 1 �� 1000: ";
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