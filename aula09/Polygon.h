#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

class Polygon{
    public:
        Polygon(){
            points = {};
        }
        Polygon(vector<Point> v){
            points = v;
        }
        bool get_vertex(size_t i, Point& p) const;
        void add_vertex(size_t i, Point p);
        void show() const;
        float perimeter() const;
    private:
        vector<Point> points; 
};

#endif