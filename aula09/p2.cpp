#include <iostream>
#include <vector>
#include "Date.h" 
#include "Person.h"

using namespace std;

void born_before(const vector<Person>& persons, const Date& date){
    date.show(); cout << ":";
    for(Person p: persons){
        if(p.get_birth_date().is_before(date)){
            cout << " "; cout << p.get_name() << "-"; p.get_birth_date().show();
        }
    }
}

int main(){
    return 0;
}

// make PROG=p2 CPP_FILES="Date.cpp Person.cpp p2.cpp" HEADERS="Date.h Person.h"
