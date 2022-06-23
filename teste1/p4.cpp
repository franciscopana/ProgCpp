#include <iostream>
using namespace std;
 
//! Fraction
struct fraction {
  int num;  // Numerator
  int den;  // Denominator
};
 
//! Compute the gcd of two numbers.
int gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
fraction mult(fraction f1, fraction f2){
    int x = f1.num * f2.num;
    int y = f1.den * f2.den;
    int g = gcd(x,y);
    x = x/g;
    y = y/g;
    x = (y > 0) ? x : -x;
    y = (y > 0) ? y : -y;
    fraction result = {x,y};
    return result;
}

fraction sum(fraction f1, fraction f2){
    int x = f1.num * f2.den + f1.den * f2.num;
    int y = f1.den * f2.den;
    int g = gcd(x,y);
    x = x/g;
    y = y/g;
    x = (y > 0) ? x : -x;
    y = (y > 0) ? y : -y;
    fraction result = {x,y};
    return result;
}

fraction exponent(fraction x, int y){
    fraction result = x;
    for(int i = 0; i < y-1; i++){
        result = mult(result,x);
    }
    return result;
}

fraction eval(const fraction a[], int n, fraction x){
    fraction result = a[0];
    for(int i = 1; i < n; i++){
        fraction f = a[i];
        fraction n = mult(f, exponent(x, i));
        result = sum(result, n);
    }
    return result;
}
