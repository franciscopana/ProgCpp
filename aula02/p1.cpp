#include <iostream>

using namespace std;

int adigits(int a, int b, int c){
    if (a >= b && a >= c){
        if (b >= c) return a * 100 + b * 10 + c;
        if (c > b) return a * 100 + c * 10 + b;
    }
    if (b >= a && b >= c){
        if (a >= c) return b * 100 + a * 10 + c;
        if (c > a) return b * 100 + c * 10 + b;
    }
    if (b>a){
        return c * 100 + b * 10 + a;
    }
    return c * 100 + a * 10 + b;
}