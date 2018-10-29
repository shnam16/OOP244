//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/10/29
#define _CRT_SERCURE_NO_WARNINGS
#include "Contact.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

  Contact::Contact() {
    name[0] = '\0';
    phoneNum = nullptr;
    number = 0;
  }

  Contact::Contact(const char* m_name, const long long* phone, int num) {
    
    if (m_name != nullptr && m_name != '\0') {
      strncpy(name, m_name, MAX_CHAR);
      name[MAX_CHAR] = '\0';
    }
    else {
      name[0] = '\0';
    }

    if (phone != nullptr && num > 0) {

      bool valid;
      int count = 0;
      for (int i = 0; i < num; i++) {
        valid = isValid(phone[i]);
        if (valid) count++;
      }
      number = count;
      phoneNum = new long long[number];

      for (int i = 0, j = 0; i < num; i++) {
        valid = isValid(phone[i]);
        if (valid) {
          phoneNum[j] = phone[i];
          j++;
        }
      }
    }

    else {
      phoneNum = nullptr;
      number = 0;
    }

    
  }


  Contact::~Contact() {
    delete[] phoneNum;
    phoneNum = nullptr;
  }

  bool Contact::isEmpty() const{
    if (name[0] == '\0') {
      return true;
    }
    else {
      return false;
    }
  }

  void Contact::display() const {

    if (isEmpty()) {
      cout << "Empty contact!" << endl;
    }

    else {
      cout << name << endl;

      for (int i = 0; i < number; i++) {

        long long a = phoneNum[i] / 10000000000LL;
        long long b = (phoneNum[i] % 10000000000LL) / 10000000LL;
        long long c = ((phoneNum[i] % 10000000000LL) % 10000000LL) / 10000LL;
        long long d = ((phoneNum[i] % 10000000000LL) % 10000000LL) % 10000LL;


        cout << "(+" << a << ") " << b << " " << c << "-";

        if (d < 1000) {
          cout.fill('0');
          cout.width(4);
          cout << d << endl;
        }
        else {
          cout << d << endl;
        }

      }
    }
  }


  bool Contact::isValid(const long long phone) {

    bool value = phone < 999999999999LL && phone >= 10000000000LL &&
      (phone % 10000000000LL) >= 1000000000LL && (phone % 10000000LL) >= 1000000LL;

    return value;

  }
}