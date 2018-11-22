//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/12


#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H

#include <iostream>

namespace sict {

  class iAccount {
  public:
    virtual bool credit(double) = 0;
    virtual bool debit(double) = 0;
    virtual void monthEnd() = 0;
    virtual void display(std::ostream&) const = 0;
  
    virtual ~iAccount() {};
  };

  iAccount* CreateAccount(const char*, double);
}

#endif // !SICT_IACCOUNT_H

