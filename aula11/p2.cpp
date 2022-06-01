#include <iostream>
#include <iomanip>
#include <cmath>
#include "Shape.h"


using namespace std;

double distance (const point p1, const point p2){
    return ( sqrt (pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2)));
}

class Circle: public Shape{
    public:

        Circle(point c, double radius): Shape(c)
        {
            radius_ = radius;
        }
        double area() const override {return M_PI * pow(radius_,2);}
        double perimeter() const override {return M_PI * 2*radius_;}
        bool contains(const point& p) const override {
            return distance(p, get_center()) > radius_? false: true;
        }

    private:
        double radius_;
};

class Rectangle: public Shape{
    public:

        Rectangle(point c, double w, double h): Shape(c)
        {
            w_ = w;
            h_ = h;
        }
        double area() const override {return w_ * h_;}
        double perimeter() const override {return 2*h_+ 2*w_;}
        bool contains(const point& p) const override {
            return ((abs(p.x - get_center().x) <= w_/2) && abs(p.y - get_center().y) <= h_/2)? true: false;
        }


    private:
        double w_;
        double h_;
};

int main(){
    return 0;
}