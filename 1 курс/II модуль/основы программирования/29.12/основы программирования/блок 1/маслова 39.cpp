//Maslova Anastasia, RUDN, NKNbd-01-21, 10.11.2021, 14:11
#include <stdio.h>
//39. Даны длины сторон прямоугольного параллелепипеда. Найти его объем и площадь боковой поверхности.

int main(){
    float v,s,a,b,c;
    printf("Программа вычисления объема и площади боковой поверхности прямоугольного параллелепипеда на основе длин его сторон.\n");
    do{
    printf("Введите сторону а: ");
    scanf("%f",&a);
    }while(a<=0);
    do{
    printf("Введите сторону b: ");
    scanf("%f",&b);
    }while(b<=0);
    do{
    printf("Введите сторону c: ");
    scanf("%f",&c);
    }while(c<=0);
    v = a*b*c;
    s = 2*a*c+2*b*c;
    printf("Объем фигуры: %f\n", v);
    printf("Площадь боковой поверхности фигуры: %f\n",s);
return 0;
}