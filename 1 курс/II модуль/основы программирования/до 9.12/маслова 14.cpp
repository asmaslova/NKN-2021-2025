//Maslova Anastasia, RUDN, NKNbd-01-21, 17.11.21, 13:04
#include <stdio.h>
#include <iostream>
//14. Даны три числа. Найти среднее из них (то есть число, расположенное между наименьшим и наибольшим).
int
main ()
{
    int a, b, c;
    printf ("Программа для вычисления среднего числа среди трех данных.\n");
    do
    {
      printf ("Введите три числа: ");
      scanf ("%i%i%i", &a, &b, &c);
    }
    while (a == b || a == c || b == c || a == b == c);
    if (a<b && b<c || c<b && b<a)
        printf ("Среднее число: %i", b);
    else if (b<a && a<c || c<a && a<b)
        printf ("Среднее число: %i", a);
    else printf ("Среднее число: %i", c);
return 0;
}
