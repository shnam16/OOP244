//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/10/29

#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_

namespace sict {

  const int MAX_CHAR = 20;

  class Contact {

    char name[MAX_CHAR];
    long long* phoneNum;
    int number;

  public:
    Contact();
    Contact(const char*, const long long*, int);
    ~Contact();
    bool isEmpty() const;
    void display() const;
    bool isValid(const long long);
  };
}




#endif