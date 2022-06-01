// Exercise 3

#include "MovingAverage.h"
#include <iostream>

using namespace std;

MovingAverage::MovingAverage(size_t n){
    n_ = n;
}

void MovingAverage::update(double value){
    if(n_ == values_.size()){
        values_.pop_front();
    }
    values_.push_back(value);
}

double MovingAverage::get() const{
    double count = 0;
    for(double v: values_){
        count += v;
    }
    return count/values_.size();
}
