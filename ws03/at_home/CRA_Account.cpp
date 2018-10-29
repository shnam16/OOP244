#include <iostream>
#include "CRA_Account.h"
#include <cstring>
#include <iomanip>
using namespace std;

namespace sict {

  void CRA_Account::set(const char* a, const char* b, int c) {
    
    int sinNum = c;
    int sum = 0;
    int num = 0;
    int digit[9];
    int i = 0;

    for (int z = 1; z <= 9; z++) {
      digit[i] = sinNum % 10;
      sinNum = sinNum / 10;

      if (i != 0 && (i % 2) == 0) {
        sum += digit[i];
      }
      else if (i != 0 && (i % 2) != 0) {
        digit[i] = digit[i] * 2;
        
        for (int y = 0; y < 2; y++) {
          num = digit[i] % 10;
          digit[i] = digit[i] / 10;
          sum += num;
        }
         
      }
      i++;
    }
    int high = ((sum / 10) + 1) * 10;
    int diff = high - sum;

    if (diff == digit[0] && c <= max_sin && c >= min_sin && strlen(a) > 0 && strlen(b) > 0) {
      numYears = 0;
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

      for (int i = 0; i < max_yrs; i++) {

        if (tax[i] != 0) {

          cout << fixed;
          cout << setprecision(2);

          if (balance[i] > 2) {
            cout << "Year (" << tax[i] << ") balance owing: " << balance[i] << endl;
          }
          else if (balance[i] < -2) {
            cout << "Year (" << tax[i] << ") refund due: " << -(balance[i]) << endl;
          }
          else {
            cout << "Year (" << tax[i] << ") No balance owing or refund due!" << endl;
          }
        }

        else
          break;
      }
    }
  }

  void CRA_Account::set(int a, double b) {

    for (int i = 0; i < max_yrs; i++) {
      if (tax[i] == 0) {
        tax[i] = a;
        balance[i] = b;
        break;
      }
    }
  }


}