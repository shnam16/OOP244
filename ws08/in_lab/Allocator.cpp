//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/12


#include "SavingsAccount.h"

namespace sict {

  const double rate = 0.05;

  iAccount* CreateAccount(const char* type, double balance) {

    iAccount* account = nullptr;

    if (type[0] == 'S') {
      account = new SavingsAccount(balance, rate);
      return account;
    }

    else {
      return account;
    }

  }
}