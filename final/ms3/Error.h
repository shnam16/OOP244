//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/21

#ifndef AID_ERROR_H
#define AID_ERROR_H

#include <iostream>
using namespace std;

namespace aid {

  class Error {
    char* error_message;

  public:
    
    explicit Error(const char* errorMessage = nullptr);
    Error(const Error& em) = delete;
    Error& operator=(const Error& em) = delete;
    virtual ~Error();
    void clear();
    bool isClear() const;
    void message(const char* str);
    const char* message() const;
  };
  ostream& operator<< (ostream& os, Error& em);
}


#endif // !AID_ERROR_H

