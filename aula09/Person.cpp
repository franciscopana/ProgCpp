#include "Person.h"
Person::Person()
{
    name_ = "NO_NAME"; 
    birth_date_ = Date();
}

Person::Person(const std::string &name, const Date &birthDate){
    name_ = name;
    birth_date_ = birthDate;
}

Date Person::get_birth_date() const{
    return birth_date_;
}

std::string Person::get_name() const{
    return name_;
}
