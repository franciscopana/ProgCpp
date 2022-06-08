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
    return 0;
}