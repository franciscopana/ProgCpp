#include <iostream>
#include <cmath>

using namespace std;

class Fraction {
  public:
    // constructors
    Fraction();
    Fraction(int numerator, int denominator);
    // accessors
    int get_numerator() const {return numerator;}
    int get_denominator() const {return denominator};
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
      numerator = x;
    }

  private:
    int numerator;
    int denominator;
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
  int g = gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;
  if (denominator < 0) {
    numerator = - numerator;
    denominator = - denominator;
  }
}

int Fraction::get_denominator() const{
    return denominator;
}

// shows fraction f on the screen
void Fraction::write() const {
  cout << numerator << '/' << denominator << endl;
}

// constructors
Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
    this->normalise();
}

// operations over fractions
Fraction Fraction::sum(const Fraction& right){
    Fraction result;
    result.numerator = this->numerator * right.denominator + this->denominator * right.numerator;
    result.denominator = this->denominator * right.denominator;
    result.normalise();
    return result;
}

Fraction Fraction::sub(const Fraction& right){
    Fraction result;
    result.numerator = this->numerator * right.denominator - this->denominator * right.numerator;
    result.denominator = this->denominator * right.denominator;
    result.normalise();
    return result;
}

Fraction Fraction::mul(const Fraction& right){
    this->numerator = this->numerator * right.numerator;
    this->denominator = this->denominator * right.denominator;
    this->normalise();
    return *this;
}

Fraction Fraction::div(const Fraction& right){
    this->numerator = this->numerator * right.denominator;
    this->denominator = this->denominator * right.numerator;
    this->normalise();
    return *this;
}

int main(){
    return 0;
}