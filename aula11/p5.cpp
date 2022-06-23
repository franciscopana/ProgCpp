#include <iostream>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

#include <iostream>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

void HourlyEmployee::calculate_net_pay(){
  set_net_pay(wage_rate_*hours_);
}

void SalariedEmployee::calculate_net_pay(){
  set_net_pay(salary_);
}

void read_hours_worked(vector<Employee*> &employees){
    for(Employee* worker : employees){
        HourlyEmployee* w = dynamic_cast<HourlyEmployee*>(worker);
        if(w != nullptr){
            double h;
            cin >> h;
            w->set_hours(h);
        }
    }
}

void calculate_pay(vector<Employee*>& employees){
    for(Employee* worker : employees){
        worker->calculate_net_pay();
    }
}

void print_checks(vector<Employee*>& employees){
    cout << "| ";
    for(Employee* worker : employees){
        worker->print_check();
        cout << " | ";
    }
}

int main(){
    return 0;
}

// make PROG=p5 CPP_FILES="Employee.cpp SalariedEmployee.cpp HourlyEmployee.cpp p5.cpp" HEADERS="Employee.h SalariedEmployee.h HourlyEmployee.h"
