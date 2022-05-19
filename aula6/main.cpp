#include <iostream>
#include "p5.cpp"

int main() {
    smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
        r);
    print(r);
    return 0;
}
