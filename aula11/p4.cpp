#include <iostream>
#include "Figure.h"

using namespace std;

class Rectangle: public Figure{
    public:
        Rectangle(double xc, double yc, double w, double h) : Figure(xc, yc){w_ = w; h_ = h;}
        void draw() const override {
            cout << "R(" << x_center_ << "," << y_center_ << ")(" << w_ << "," << h_ << ")";
        }
    private:
        double w_, h_;
};

class Circle: public Figure{
    public:
        Circle(double xc, double yc, double r) : Figure(xc, yc){r_ = r;}
        void draw() const override {
            cout << "C(" << x_center_ << "," << y_center_ << ")(" << r_ << ")";
        }
    private:
        double r_;
};

int main(){
    return 0;
}