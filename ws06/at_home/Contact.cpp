//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/10/31
#define _CRT_SERCURE_NO_WARNINGS
#include "Contact.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

  Contact::Contact() {
    name[0] = '\0';
    number = 0;
    phoneNum = nullptr;
  }

  Contact::Contact(const char* m_name, const long long* phone, int num) {
    
    if (m_name == nullptr) {
      *this = Contact();
      
    }
    else {
      strncpy(name, m_name, MAX_CHAR);
      name[MAX_CHAR - 1] = '\0';
     
      bool valid;
      int count = 0;

      if (phone != nullptr) {

       
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

    
  }


  Contact::~Contact() {
    delete[] phoneNum;
   
    
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

  Contact::Contact(const Contact& src) {

    strncpy(name, src.name, MAX_CHAR);
    name[MAX_CHAR - 1] = '\0';
    number = src.number;
    
    if (src.phoneNum != nullptr) {
      bool valid;
      int count = 0;

      for (int i = 0; i < src.number; i++) {
        valid = isValid(src.phoneNum[i]);
        if (valid) {
          count++;
        }
      }

      number = count;
      phoneNum = new long long[number];

      for (int i = 0, j = 0; i < src.number; i++) {
        valid = isValid(src.phoneNum[i]);
        if (valid) {
          phoneNum[j] = src.phoneNum[i];
          j++;
        }
      }
    }

    else {
      phoneNum = nullptr;
    }

   

  }


  Contact& Contact::operator=(const Contact& src) {

    if (this != &src) {
      strncpy(name, src.name, MAX_CHAR);
      name[MAX_CHAR - 1] = '\0';
      number = src.number;

      delete[] phoneNum;

      if (src.phoneNum != nullptr) {
        phoneNum = new long long[number];

        for (int i = 0; i < number; i++) {
          phoneNum[i] = src.phoneNum[i];
        }
      }
      else {
        phoneNum = nullptr;
      }
    }

    return *this;
  }


  Contact& Contact::operator+=(long long src) {
    bool valid;
    valid = isValid(src);

    if (valid) {
      number++;
      long long* temp = nullptr;
      temp = new long long[number];

      for (int i = 0; i < (number - 1); i++) {
        temp[i] = phoneNum[i];
      }

      delete[] phoneNum;
      phoneNum = nullptr;
      phoneNum = temp;

      phoneNum[number - 1] = src;
    }

    return *this;
  }

}