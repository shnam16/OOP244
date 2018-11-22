//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/12


#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H

#include "Account.h"

namespace sict {
  
  class SavingsAccount : public Account {

    double interestRate;

  public:
    SavingsAccount(double, double);
    void monthEnd();
    void display(std::ostream&) const;
  };


}
#endif // !SICT_SAVINGSACCOUNT_H

