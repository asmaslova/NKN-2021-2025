#include <iostream>
#include <stdio.h>
using namespace std;

int main()

{
    int d,n,a;
    cout<<"Программа для определения знака зодиака по дате рождения.\n";
    do{
    cout<<"Введите число и месяц своего рождения числами через пробел: ";
    cin>>d>>n;
    } while ((d>28 && n==2)||(d>30 && (n==4 || n==6 || n==9 || n==11)) || (d>31 && (n==1 || n==3 || n==5 || n==7 || n==8 || n==10 || n==12)) || (d<1) || (n<1));
    switch (n) {
        case 1: goto january;
        case 2: goto february;
        case 3: goto march;
        case 4: goto april;
        case 5: goto may;
        case 6: goto june;
        case 7: goto july;
        case 8: goto august;
        case 9: goto september;
        case 10: goto october;
        case 11: goto november;
        case 12: goto december;
    }
    
    january:
        switch (d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21:
                a = 1; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 2; goto output;
        }
    
    february:
        switch (d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 2; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28:
                a = 3; goto output;
        }
    
    march:
        switch (d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 3; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 4; goto output;
        }
    
    april:
        switch (d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 4; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
                a = 5; goto output;
        }

    may:
        switch (d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 5; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 6; goto output;
        }
    
    june:
        switch (d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 6; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
                a = 7; goto output;
        }
    
    july:
        switch(d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 7; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 8; goto output;
        }
    
    august:
        switch(d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 8; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 9; goto output;
        }
    
    september:
        switch(d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 9; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
                a = 10; goto output;
        }
    
    october:
        switch(d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 10; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 11; goto output;
        }
    
    november:
        switch(d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 11; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30:
                a = 12; goto output;
        }
    
    december:
        switch(d){
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 21:
                a = 12; goto output;
            case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:
                a = 1; goto output;
        }
    
    output:
        switch (a){
            case 1: cout<<"Ваш знак зодиака - козерог."; break;
            case 2: cout<<"Ваш знак зодиака - водолей."; break;
            case 3: cout<<"Ваш знак зодиака - рыбы."; break;
            case 4: cout<<"Ваш знак зодиака - овен."; break;
            case 5: cout<<"Ваш знак зодиака - телец."; break;
            case 6: cout<<"Ваш знак зодиака - близнецы."; break;
            case 7: cout<<"Ваш знак зодиака - рак."; break;
            case 8: cout<<"Ваш знак зодиака - лев."; break;
            case 9: cout<<"Ваш знак зодиака - дева"; break;
            case 10: cout<<"Ваш знак зодиака - весы"; break;
            case 11: cout<<"Ваш знак зодиака - скорпион."; break;
            case 12: cout<<"Ваш знак зодиака - стрелец."; break;
            default: break;
        }
    
    
    return 0;
}
