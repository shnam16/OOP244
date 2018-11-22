//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/12


#include "SavingsAccount.h"

#include <iostream>
#include <iomanip>

namespace sict {

  SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance) {
    
    if (interest > 0) {
      interestRate = interest;
    }

    else {
      interestRate = 0.0;
    }
  }


  void SavingsAccount::monthEnd() {

    double interestCharge;
    interestCharge = Account::balance() * interestRate;
    Account::credit(interestCharge);
  }



  void SavingsAccount::display(std::ostream& os) const {

    double totalBalance = Account::balance();

    os << "Account type: Savings" << std::endl;

    os << "Balance: $" << std::fixed << std::setprecision(2) << totalBalance << std::endl;
    os << "Interest Rate (%): " << std::fixed << std::setprecision(2) << interestRate * 100 << std::endl;


  }


}