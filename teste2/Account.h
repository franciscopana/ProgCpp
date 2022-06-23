#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
  Account(int number) : number_(number) { }
  int get_number() const { return number_; }
  virtual float get_balance() const = 0;
protected:
  int number_;
};

#endif
