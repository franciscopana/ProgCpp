#include <math.h>
#include "Point.h"

float Point::distance(Point p) const{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}