#include <iostream>

using namespace std;

int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

struct fraction {
   int num; // Numerator
   int den; // Denominator
}; 

fraction sum(const fraction fa[], int n){
    fraction result = {0, 1};
    for(int i = 0; i < n; i++){
        fraction f = fa[i];
        int x = result.num * f.den + result.den * f.num;
        int y = result.den * f.den;
        int g = gcd(x,y);
        x = x/g;
        y = y/g;
        result.num = (y>0) ? x: -x;
        result.den = (y>0) ? y: -y;
    }
    return result;
}