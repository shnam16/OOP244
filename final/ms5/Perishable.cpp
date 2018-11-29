//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/28

#include <iostream>
#include "Perishable.h"

using namespace std;

namespace aid {

  Perishable::Perishable() : Good('P') {

    error_state.clear();
  }


  fstream& Perishable::store(fstream& file, bool newLine) const {

    Good::store(file, false);

    file << "," << expiry_date << endl;

    return file;
  }


  fstream& Perishable::load(fstream& file) {

    Good::load(file);
    expiry_date.read(file);
    file.ignore();

    return file;

  }

  ostream& Perishable::write(ostream& os, bool linear) const {

    Good::write(os, linear);

    if (isClear() && !isEmpty()) {

      if (linear) {

        expiry_date.write(os);
      }

      else {

        os << "\n Expiry date: ";
        expiry_date.write(os);
      }

    }

    return os;
  }


  istream& Perishable::read(istream& is) {

    is.clear();
    Good::read(is);
    

    if (error_state.isClear()) {

      cout << " Expiry date (YYYY/MM/DD): ";
      expiry_date.read(is);
    }

    if (expiry_date.errCode() == CIN_FAILED) {
      error_state.clear();
      error_state.message("Invalid Date Entry");
    }

    else if (expiry_date.errCode() == YEAR_ERROR) {
      error_state.clear();
      error_state.message("Invalid Year in Date Entry");
      
    }

    else if (expiry_date.errCode() == MON_ERROR) {
      error_state.clear();
      error_state.message("Invalid Month in Date Entry");
    }

    else if (expiry_date.errCode() == DAY_ERROR) {
      error_state.clear();
      error_state.message("Invalid Day in Date Entry");
    }
    
    else if (expiry_date.errCode() == PAST_ERROR) {
      error_state.clear();
      error_state.message("Invalid Expiry in Date Entry");
    }

    if (expiry_date.errCode()) {
      is.setstate(ios::failbit);
    }
    if (expiry_date.errCode() != CIN_FAILED && expiry_date.errCode() != YEAR_ERROR && expiry_date.errCode() != MON_ERROR && expiry_date.errCode() != DAY_ERROR && expiry_date.errCode() != PAST_ERROR) {
      error_state.clear();
    }



    return is;
  }


  const Date& Perishable::expiry() const {

    return expiry_date;
  }
}