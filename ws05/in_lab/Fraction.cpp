// TODO: insert header files
#include "Fraction.h"
#include <iostream>
using namespace std;
// TODO: continue the namespace
namespace sict {
  // TODO: implement the default constructor
  Fraction::Fraction() {
    numerator = 0;
    denominator = 0;
  }
  // TODO: implement the two-argument constructor
  Fraction::Fraction(int a, int b) {
    if (a >= 0 && b > 0) {
      numerator = a;
      denominator = b;
      reduce();
    }
    else {
      numerator = 0;
      denominator = 0;
     
    }
  }
  // TODO: implement the max query
  int Fraction::max() const {
    int i;
    i = (numerator > denominator) ? numerator : denominator;

    return i;
  }

    // TODO: implement the min query
  int Fraction::min() const {
    int i;
    i = (numerator < denominator) ? numerator : denominator;
    
    return i;
  }
  // gcd returns the greatest common divisor of num and denom
    //
  int Fraction::gcd() const {
    int mn = min();  // min of numerator and denominator
    int mx = max();  // max of numerator and denominator
    int g_c_d = 1;
    bool found = false;

    for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
      if (mx % x == 0 && mn % x == 0) {
        found = true;
        g_c_d = x;
      }
    }
    return g_c_d;
  }

  // TODO: implement the reduce modifier
  void Fraction::reduce() {
    int i;
    i = gcd();
    numerator /= i;
    denominator /= i;
  }
  // TODO: implement the display query
  void Fraction::display() const {
    if (numerator >= 0 && denominator > 1) {
      cout << numerator << "/" << denominator;
    }
    else if (numerator >= 0 && denominator == 1) {
      cout << numerator;
    }
    else {
      cout << "no fraction stored";
    }
  }
  // TODO: implement the isEmpty query
  bool Fraction::isEmpty() const {
    if (numerator == 0 && denominator == 0) {
      return true;
    }
    else {
      return false;
    }

  }
  // TODO: implement the + operator
  Fraction Fraction::operator+(const Fraction& rhs) const {
    Fraction temp;
    if (this->isEmpty() && !rhs.isEmpty()) {
      return *this;
    }
    else if (!this->isEmpty() && rhs.isEmpty()) {
      return rhs;
    }
    else if (this->isEmpty() && rhs.isEmpty()) {
      return rhs;
    }
    else {
      temp.denominator = this->denominator * rhs.denominator;
      temp.numerator = this->numerator*rhs.denominator + this->denominator*rhs.numerator;
      temp.reduce();
      return temp;
    }
  }

}