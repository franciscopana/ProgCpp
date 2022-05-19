#include "Polygon.h"

bool Polygon::get_vertex(size_t i, Point& p) const{
    if(i > points.size() || i <= 0) return false;
    p = points[i-1];
    return true;
}

void Polygon::add_vertex(size_t i, Point p){
    if(!(i <= 0 || i > points.size()+1))
        points.insert(points.begin() + i-1, p);
}

float Polygon::perimeter() const{
    float result = 0;
    size_t i = 0;
    while(i < points.size()-1){
        result += points[i].distance(points[i+1]);
        i++;
    }
    result += points[i++].distance(points[0]);
    return result;
}

void Polygon::show() const{
    cout << '{';
    for(Point p: points){
        p.show();
    }
    cout << '}';
}