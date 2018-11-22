//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/16


#include "iAccount.h"
#include "Account.h"

#include <iostream>


namespace sict {
  
  Account::Account(double balance) {

    if (balance > 0) {
      currentBalance = balance;
    }

    else {
      currentBalance = 0;
    }

  }



  bool Account::credit(double credit) {

    if (credit > 0) {
      currentBalance += credit;
      return true;
    }
    
    else {
      return false;
    }
  }



  bool Account::debit(double debit) {

    if (debit > 0) {
      currentBalance -= debit;
      return true;
    }
    else {
      return false;
    }
  }


  double Account::balance() const {
    return currentBalance;
  }


}
