#include <iostream>

using namespace std;

bool is_leap_year(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int days_in_month(int m, int y) {
    int d;
    if (m == 2)
        d = is_leap_year(y) ? 29 : 28;
    else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        d = 31;
    else
        d = 30;
    return d;
}

void advance(int delta, int& d, int& m, int& y){
    for (int i = 0; i < delta; i++){
        int days_month = days_in_month(m, y);
        if (d < days_month){
            d++;
        }
        else if (m < 12){
            d = 1;
            m++;
        }
        else {
            d = 1;
            m = 1;
            y++;
        }
    }
}