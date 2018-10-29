#include <iostream>
#include "CRA_Account.h"
#include <cstring>

using namespace std;

namespace sict {

  void CRA_Account::set(const char* a, const char* b, int c) {

    if (c >= min_sin && c <= max_sin) {

      strncpy(family_name, a, (strlen(a) + 1));
      strncpy(given_name, b, (strlen(b) + 1));
      sin = c;
    }

    else {
      sin = 0;
    }
  }


  bool CRA_Account::isEmpty() const {
    if (sin == 0) {
      return true;
    }
    else {
      return false;
    }
  }


  void CRA_Account::display() const {
    if (isEmpty() == true) {
      cout << "Account object is empty!" << endl;
    }
    else {
      cout << "Family Name: " << family_name << endl;
      cout << "Given Name : " << given_name << endl;
      cout << "CRA Account: " << sin << endl;
    }
  }
}