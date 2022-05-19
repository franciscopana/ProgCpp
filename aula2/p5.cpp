#include <iostream>

using namespace std;

unsigned long factorial(unsigned long n){
    if (n == 0 || n == 1) return 1;
    return n * factorial(n-1);
}

unsigned long binomial_coefficients(unsigned long n, unsigned long k){
    unsigned long fac_n = 1;
    for(unsigned long i = n; i >= n - k + 1; i--){
        fac_n *= i;
    }
    return fac_n / factorial(k);
}

unsigned long bell(unsigned long n){
    if(n == 0 || n == 1) return 1;
    unsigned long bn = 0;
    for(unsigned long k = 0; k < n; k++){
        bn += bell(k) * binomial_coefficients(n-1, k);
    }
    return bn;
}