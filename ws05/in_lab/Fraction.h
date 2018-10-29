// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SCIT_FRACTION_H
// TODO: create namespace
namespace sict {
  // TODO: define the Fraction class
  class Fraction {
    // TODO: declare instance variables 
    int numerator;
    int denominator;
    // TODO: declare private member functions
    int max() const;
    int min() const;
    void reduce();
    int gcd() const;
  public:
    // TODO: declare public member functions
    bool isEmpty() const;
    void display() const;
    Fraction();
    Fraction(int a, int b);
    // TODO: declare the + operator overload
    Fraction operator+(const Fraction& rhs) const;
  };
}
#endif

