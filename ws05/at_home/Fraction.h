//Student Name: Seung Ho Nam
//Student Number: 148151178
//Student ID: shnam
//Date: 10/18/2018

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
    Fraction operator*(const Fraction& a) const;
    bool operator==(const Fraction& b) const;
    bool operator!=(const Fraction& c) const;
    Fraction& operator+=(const Fraction& d);
  };
}
#endif

