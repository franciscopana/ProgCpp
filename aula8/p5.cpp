#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
  public:
    // constructors
    Fraction();
    Fraction(int num, int den);
    // accessors
    int get_num() const {return num;}
    int get_denominator() const {return den;}
    // operations
    Fraction sum(const Fraction& right);
    Fraction sub(const Fraction& right);
    Fraction mul(const Fraction& right);
    Fraction div(const Fraction& right);
    // other  member functions
    void normalise();
    int gcd(int a, int b);
    void write() const;
    //setter
    void set_num(int x){
      num = x;
    }

  private:
    int num;
    int den;
};

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction.
void Fraction::normalise() {
  int g = gcd(num, den);
  num /= g;
  den /= g;
  if (den < 0) {
    num = - num;
    den = - den;
  }
}

// shows fraction f on the screen
void Fraction::write() const {
  cout << num << '/' << den;
}

// constructors
Fraction::Fraction(){
    num = 0;
    den = 1;
}

Fraction::Fraction(int num, int den){
    this->num = num;
    this->den = den;
    this->normalise();
}

// operations over fractions
Fraction Fraction::sum(const Fraction& right){
    Fraction result;
    result.num = this->num * right.den + this->den * right.num;
    result.den = this->den * right.den;
    result.normalise();
    return result;
}

Fraction Fraction::sub(const Fraction& right){
    Fraction result;
    result.num = this->num * right.den - this->den * right.num;
    result.den = this->den * right.den;
    result.normalise();
    return result;
}

Fraction Fraction::mul(const Fraction& right){
    this->num = this->num * right.num;
    this->den = this->den * right.den;
    this->normalise();
    return *this;
}

Fraction Fraction::div(const Fraction& right){
    this->num = this->num * right.den;
    this->den = this->den * right.num;
    this->normalise();
    return *this;
}

int main(){
    Fraction().div({2, 4}).write(); cout << ' ';
    Fraction(1,1).div({2, 4}).write(); cout << ' ';
    Fraction(2,4).div({3, 9}).write(); cout << ' ';
    Fraction(-2,4).div({1, 2}).write(); cout << ' ';
    Fraction(3,27).div({-27, 81}).write(); cout << '\n';
    return 0;
}