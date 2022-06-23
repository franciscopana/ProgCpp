#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct course {
  std::string name;
  float credits;
  short grade;
};

class Student {
public:
  // constructor with parameters
  Student(const std::string& id);
  // accessor
  std::string get_id() const;
  // member functions
  void add(const course& c);
  double avg() const;
private:
  std::string id_;
  std::vector<course> courses_;
};

#endif
