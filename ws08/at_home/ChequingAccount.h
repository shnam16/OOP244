//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/16

#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H

#include "Account.h"

namespace sict {


  class ChequingAccount : public Account {

    double transactionFee;
    double monthEndFee;

  public:

    ChequingAccount(double, double, double);

    bool credit(double);
    bool debit(double);
    void monthEnd();
    void display(std::ostream&) const;


  };


}
#endif // !SICT_CHEQUINGACCOUNT_H

