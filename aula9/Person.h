#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "Date.h"

class Person {
public:
  Person();
  Person(const std::string& name, const Date& birth_date);
  std::string get_name() const;
  Date get_birth_date() const;
  void show() const { std::cout << name_ << "-"; birth_date_.show(); }
private:
  std::string name_;
  Date birth_date_;
};

#endif
