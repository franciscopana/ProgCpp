#include <iostream>
#include <iomanip>
#include "Student_b.h"

using namespace std;

Student::Student(const string& id){
    id_ = id;
}

string Student::get_id() const{
    return id_;
}

void Student::add(const course& c){
    courses_.push_back(c);
}

double Student::avg() const{
    double average = 0;
    double total_credits = 0;
    for(course c: courses_){
        average += c.credits*c.grade;
        total_credits += c.credits;
    }
    if(total_credits == 0) return 0;
    return average/total_credits;
}

int main(){
    return 0;
}