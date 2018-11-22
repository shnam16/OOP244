//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/16


#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {

  const double rate = 0.05;
  const double tranFee = 0.50;
  const double monthlyFee = 2.00;

  iAccount* CreateAccount(const char* type, double balance) {

    iAccount* account = nullptr;

    if (type[0] == 'S') {
      account = new SavingsAccount(balance, rate);
      return account;
    }

    else if (type[0] == 'C') {
      account = new ChequingAccount(balance, tranFee, monthlyFee);
      return account;
    }

    else {
      return account;
    }

  }
}