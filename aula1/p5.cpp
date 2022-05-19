#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int k, d;
    cin >> k >> d;

    cout.precision(d);
    cout << fixed;

    double result;
    for(int n=0; n<=k; n++){
        result += pow(-1, n)/(2*n+1);
    }
    result *= 4;
    cout << result << endl;
    return 0;
}
