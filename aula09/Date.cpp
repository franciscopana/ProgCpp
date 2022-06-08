#include "Date.h"

using namespace std;

Date::Date(){
    year_ = 1;
    month_ = 1;
    day_ = 1;
}

Date::Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

bool Date::is_before(const Date& date2) const{
    int num1 = year_*10000 + month_*100 + day_; 
    int num2 = date2.year_*10000 + date2.month_*100 + date2.day_;
    return num1 < num2;
}