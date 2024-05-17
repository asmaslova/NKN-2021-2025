#include <iostream>
#include <string>
using namespace std;

class Date{
public:
    unsigned int Year;
    string Month;
    unsigned int Day;
    string DayWeek;
} D;
int main(){
    Date D1;
    D1.Year=2015;
    D1.Month = "September";
    D1.Day = 29;
    D1.DayWeek = "Monday";
    cout<<"Today is "<<D1.Day<<"."<<D1.Month<<"."<<D1.Year<<", "<<D1.DayWeek;
}