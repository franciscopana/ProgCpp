#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "Point2d.h"

void Point2d::translate(const Point2d& t){
    this->x += t.x;
    this->y += t.y;
}

double Point2d::distance_to(const Point2d& p) const{
    return sqrt(pow(this->x + p.x, 2) + pow(this->y + p.y, 2));
}

int main(){
    Point2d a { 1.0, 2.1 };
    a.translate({ -0.3, 0.5 });
    cout << fixed << setprecision(2) 
        << a.get_x() << ' ' << a.get_y() << '\n';
    return 0;
}