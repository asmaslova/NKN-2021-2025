//29.12.2021 RUDN NKNbd-01-21 Maslova Anastasia
//14. Определить класс с именем Credit содержащий следующие данные класса: 
//название кредитной программы; процентная ставка по кредиту; срок предоставления кредита; сумма переплаты. 
#include <iostream>
#include <string>
using namespace std;

class credit
{
public:
    string CreditProgramName;
    float Procent;
    int Period; //months
    float Overpaying;
};

int main()
{
    credit credit1;
    credit1.CreditProgramName = "The first credit program";
    credit1.Overpaying = 1452.12;
    credit1.Period = 23;
    credit1.Procent = 12.5;
    cout<<"You're going to take "<<credit1.CreditProgramName<<" for "<<credit1.Period<<" months. Your procent is "<<credit1.Procent<<"%. Your overpaying is "<<credit1.Overpaying<<" rubles.";
}