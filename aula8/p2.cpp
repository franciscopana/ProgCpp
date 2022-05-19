#include <iostream>
#include <iomanip>
#include "Date1.h"
 
using namespace std;

Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::get_day() const{
    return this->day;
}

int Date::get_month() const{
    return this->month;
}

int Date::get_year() const{
    return this->year;
}

bool is_before(const Date& date1, const Date& date2){
    int num1 = date1.get_year()*10000 + date1.get_month()*100 + date1.get_day(); 
    int num2 = date2.get_year()*10000 + date2.get_month()*100 + date2.get_day();
    return num1 < num2;
}

int main(){
    return 0;
}