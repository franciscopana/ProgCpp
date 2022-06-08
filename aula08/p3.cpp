#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date2.h"

using namespace std;

int days_in_month(int year, int month) {
    int feb = (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))? 29 : 28;
    int n_days[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return n_days[month - 1];
}

Date::Date(){
    year = 1;
    month = 1;
    day = 1;
}

Date::Date(int year, int month, int day) {
    if(day <= days_in_month(year, month) && year >= 1 &&year <= 9999){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else{
        this->year = this->month = this->day = 0;
    }
}

Date::Date(const std::string& year_month_day){
    istringstream stream(year_month_day);
    int year, month, day;
    char s1, s2;
    if(stream >> year >> s1 >> month >> s2 >> day && s1 == s2 && s1 == '/' && day <= days_in_month(year, month) && year >= 1 && year <= 9999){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else{
        this->year = 0;
        this->month = 0;
        this->day = 0;
    }
}

bool Date::is_valid() const{
    return !(this->day == 0 || this->month == 0 || this->year == 0);
}

int main(){
    return 0;
}