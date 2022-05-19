#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2){
    double delta = b * b - 4 * a * c;
    if (delta < 0){
        x1 = std::numeric_limits<double>::quiet_NaN();
        x2 = std::numeric_limits<double>::quiet_NaN();
        return 0;
    }
    else if(delta == 0){
        x1 = -b / (2.0*a);
        x2 = std::numeric_limits<double>::quiet_NaN();
        return 1;
    }
    x1 = (-b - sqrt(delta)) / (2.0*a);
    x2 = (-b + sqrt(delta)) / (2.0*a);
    return 2;
}