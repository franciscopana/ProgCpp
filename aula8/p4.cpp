#include <iostream>
#include <iomanip>
#include <sstream>
#include "Date3.h"
 
using namespace std;

int days_in_month(int year, int month) {
    int feb = (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))? 29 : 28;
    int n_days[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return n_days[month - 1];
}

Date::Date(){
    yyyymmdd = "00010101";
}

Date::Date(int year, int month, int day){
    if(day <= days_in_month(year, month) && year >= 1 && year <= 9999){
        ostringstream oss;
        oss << setfill('0') << setw(4) << year << setw(2) << month << setw(2) << day;
        yyyymmdd = oss.str();
    }
    else{
        yyyymmdd = "00000000";
    }
}

Date::Date(const std::string& year_month_day){
    istringstream stream(year_month_day);
    int year, month, day;
    char s1, s2;
    if(stream >> year >> s1 >> month >> s2 >> day && s1 == s2 && s1 == '/' && day <= days_in_month(year, month) && year >= 1 && year <= 9999){
        ostringstream oss;
        oss << setfill('0') << setw(4) << year << setw(2) << month << setw(2) << day;
        yyyymmdd = oss.str();
    }
    else{
        yyyymmdd = "00000000";
    }
}
int Date::get_day() const{
    return stoi(yyyymmdd.substr(6, 2));
}

int Date::get_month() const{
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_year() const{
    return stoi(yyyymmdd.substr(0, 4));
}

bool Date::is_valid() const{
    return !(yyyymmdd == "00000000");
}

int main(){
    Date d1;
    return 0;
}