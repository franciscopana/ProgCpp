#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <math.h>

class Point{
    public:
        Point(){
            x = 0; y = 0;
        }
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }
        float distance(Point p) const;
        void show() const{
            std::cout << '(' << x << ',' << y << ')';
        }
    private:
        int x, y;
};

#endif