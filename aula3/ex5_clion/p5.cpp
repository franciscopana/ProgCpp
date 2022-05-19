#include <iostream>

using namespace std;

struct time_of_day {
    unsigned char h;  // hours (0 to 23)
    unsigned char m;  // minutes (0 to 59)
};
struct interval {
    time_of_day start;  // start time
    time_of_day end;    // end time
};

//! Prints the results.
void print(int d, const interval il) {
    cout << d << " ["
         << (int) il.start.h << ':' << (int) il.start.m << ','
         << (int) il.end.h   << ':' << (int) il.end.m
         << "[\n";
}

int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    time_of_day min_u = {23, 59}, max_u = {0, 0};
    bool found = false;
    for(int i = 0; i < n; i++){
        interval il = a[i];
        if ((t.h == il.start.h && t.m >= il.start.m) ||
            (t.h == il.end.h && t.m < il.end.m) ||
            (t.h > il.start.h && t.h < il.end.h)){
            found = true;
            if((il.start.h < min_u.h) || (il.start.h == min_u.h && il.start.m < min_u.m)){
                min_u = il.start;
            }
            if ((il.end.h > max_u.h) || (il.end.h == max_u.h && il.end.m > max_u.m)){
                max_u = il.end;
            }
        }
    }
    // if t was found in the intervals
    if (found){
        u = {min_u, max_u};
        int v = (max_u.h - min_u.h) * 60 + (max_u.m - min_u.m);
        return v;
    }
    // t not in the intervals
    u = {t,t};
    return 0;
}