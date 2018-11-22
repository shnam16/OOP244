//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/12


#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

#include "iAccount.h"

namespace sict {

  class Account : public iAccount {

    double currentBalance;

  public:
    Account(double);
    bool credit(double);
    bool debit(double);
    
  protected:
    double balance() const;
  };
}
#endif // !SICT_ACCOUNT_H

