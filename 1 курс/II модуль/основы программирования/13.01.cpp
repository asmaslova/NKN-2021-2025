//14.01.2022 RUDN NKNbd-01-21 Maslova Anastasia
//14. Вывести сведения о работниках, срок действия контракта которых истекает в течении 5 дней.
#include <iostream>
#include <string>
using namespace std;

class worker
{
public:
    string surname;
    string position;
    int day; //start
    int month;
    int year;
    int period;  //in days;
    float salary;
    int day2=day2_;
    int month2 = month2_;
    int year2=year2_;
private:
    int day2_ = (day+period)%30;
    int month2_ = (month+((day+period)/30))%12;
    int year2_ = year+((day+period)/365);
};

int main()
{
    int day1, month1, year1;
    worker one, two, three, four, five;
    cout<<"Enter the data about workers: "<<endl;
    cout<<"#1. Surname: ";
    cin>>one.surname;
    cout<<"Position: ";
    cin>>one.position;
    cout<<"Date of the start of the contract: ";
    cin>>one.day>>one.month>>one.year;
    cout<<"Period of contract: ";
    cin>>one.period;
    cout<<"Salary: ";
    cin>>one.salary;
    
    cout<<"Today is "; //day month year
    cin>>day1>>month1>>year1;
    cout<<"The first worker's contract ends "<<one.day2<<"."<<one.month2<<"."<<one.year2;
}