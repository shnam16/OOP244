//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/16

#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {

  ChequingAccount::ChequingAccount(double initialBalance, double transaction_Fee, double monthly_Fee) : Account(initialBalance) {


    if (transaction_Fee > 0) {
      transactionFee = transaction_Fee;
    }

    else {
      transactionFee = 0.0;
    }

    if (monthly_Fee > 0) {
      monthEndFee = monthly_Fee;
    }

    else {
      monthEndFee = 0.0;
    }
  }



  bool ChequingAccount::credit(double credit) {

    if (Account::credit(credit)) {
      Account::debit(transactionFee);
      return true;
    }

    else {
      return false;
    }

  }


  bool ChequingAccount::debit(double debit) {

    if (Account::debit(debit)) {
      Account::debit(transactionFee);
      return true;
    }

    else {
      return false;
    }

  }


  void ChequingAccount::monthEnd() {

    Account::debit(monthEndFee);
  }



  void ChequingAccount::display(ostream& os) const {


    double total = Account::balance();

    os << "Account type: Chequing" << endl;
    os << "Balance: $" << fixed << setprecision(2) << total << endl;
    os << "Per Transaction Fee: " << fixed << setprecision(2) << transactionFee << endl;
    os << "Monthly Fee: " << fixed << setprecision(2) << monthEndFee << endl;
  }
}