//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/28
#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace aid {
  Error::Error(const char* errorMessage) {
    if (errorMessage == nullptr || errorMessage[0] == '\0') {
      error_message = nullptr;
    }
   
    else {
      error_message = new char[strlen(errorMessage) + 1];
      strcpy(error_message, errorMessage);
      error_message[strlen(errorMessage)] = '\0';
    }
  }


  Error::~Error() {
    delete[] error_message;
    error_message = nullptr;
  }


  void Error::clear() {
    delete[] this->error_message;
    error_message = nullptr;
  }

  bool Error::isClear() const {
    if (error_message == nullptr || error_message[0] == '\0') {
      return true;

    }
    else {
      return false;
    }
  }

  void Error::message(const char* str) {
    delete[] error_message;

    if (str == nullptr || str[0] == '\0') {
      error_message = nullptr;
    }
    else {
      error_message = new char[strlen(str) + 1];
      strcpy(error_message, str);
      error_message[strlen(str)] = '\0';
    }
  }

  const char* Error::message() const {
    if (error_message == nullptr || error_message[0] == '\0') {
      return nullptr;
    }
    else {
      return error_message;
    }
  }

  
  ostream& operator<<(ostream& os, Error& em) {
    if (!em.isClear()) {
      os << em.message();
    }
      return os;
    
  }

 

}