#include <iostream>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using namespace std;

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
vector<Employee*> employees = {
  new HourlyEmployee("Philip", 10.75),
  new HourlyEmployee("Elisabeth", 9.5),
  new SalariedEmployee("Charles", 5000) };
read_hours_worked(employees);
calculate_pay(employees);
print_checks(employees);
for (const auto& e : employees) delete e;
    return 0;
}