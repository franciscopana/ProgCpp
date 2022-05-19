#include <iostream>
#include "p5.cpp"

using namespace std;

int main(){
    const int n = 5;
    const time_of_day t = { 15, 15 };
    interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                { { 14, 30 }, { 15, 30 } }, 
                { { 15, 10 }, { 16, 10 } }, 
                { {  9, 30 }, { 15, 15 } }, 
                { {  9, 45 }, { 15, 16 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    print(d, u);
    return 0;
}