// Final Project Milestone 1
//
// Version 1.0
// Date 2018/11/02
// Author Seung Ho Nam
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Seung Ho Nam              Date 2018/11/02                Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"

namespace aid {

	// number of days in month mon and year year
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

  void Date::errCode(int errorCode) {
    error = errorCode;
  }

  Date::Date() {
    year = 0;
    month = 0;
    day = 0;
    comp = 0;
    errCode(NO_ERROR);
  }

  Date::Date(int y, int m, int d) {
 
    bool valid = true;

    if (y < min_year || y > max_year) {
      errCode(YEAR_ERROR);
      year = 0;
      month = 0;
      day = 0;
      comp = 0;
      valid = !(bad());
    }

    else if (m < 1 || m > 12) {
      errCode(MON_ERROR);
      year = 0;
      month = 0;
      day = 0;
      comp = 0;
      valid = !(bad());
    }

    else if (d < 1 || d > mdays(m, y)) {
      errCode(DAY_ERROR);
      year = 0;
      month = 0;
      day = 0;
      comp = 0;
      valid = !(bad());
    }

    else if (valid) {
      errCode(NO_ERROR);
      year = y;
      month = m;
      day = d;
      comp = (year * 372 + month * 31 + day);
    }
}


  bool Date::operator==(const Date& rhs) const {
    if (this == nullptr || &rhs == nullptr) {
      return false;
    }
    else if (this->comp == rhs.comp) {
      return true;
    }
    else {
      return false;
    }
  }

  bool Date::operator!=(const Date& rhs) const {
    if (this == nullptr || &rhs == nullptr) {
      return false;
    }
    else if (this->comp != rhs.comp) {
      return true;
    }
    else {
      return false;
    }
  }


  bool Date::operator<(const Date& rhs) const {
    if (this == nullptr || &rhs == nullptr) {
      return false;
    }
    else if (this->comp < rhs.comp) {
      return true;
    }
    else {
      return false;
    }
  }


  bool Date::operator>(const Date& rhs) const {
    if (this == nullptr || &rhs == nullptr) {
      return false;
    }
    else if (this->comp > rhs.comp) {
      return true;
    }
    else {
      return false;
    }
  }


  bool Date::operator<=(const Date& rhs) const {
    if (this == nullptr || &rhs == nullptr) {
      return false;
    }
    else if (this->comp <= rhs.comp) {
      return true;
    }
    else {
      return false;
    }
  }

  

  bool Date::operator>=(const Date& rhs) const {
    if (this == nullptr || &rhs == nullptr) {
      return false;
    }
    else if (this->comp >= rhs.comp) {
      return true;
    }
    else {
      return false;
    }
  }


  int Date::errCode() const {
    return error;
  }

  bool Date::bad() const {
    int x = errCode();
    if (x != 0) {
      return true;
    }
    else {
      return false;
    }
  }


  std::istream& Date::read(std::istream& istr) {
    int y;
    int m;
    int d;
    char slash = '/';

    istr >> y >> slash >> m >> slash >> d;

    if (istr.fail()) {
      errCode(CIN_FAILED);
    }
    else if (min_year > y || y > max_year) {
      errCode(YEAR_ERROR);
    }
    else if (m < 1 || 12 < m) {
      errCode(MON_ERROR);
    }
    else if (1 > d || mdays(m, y) < d) {
      errCode(DAY_ERROR);
    }
    else if (min_date > (y * 372 + m * 31 + d)) {
      errCode(PAST_ERROR);
    }
    else {
      year = y;
      month = m;
      day = d;
    }
    return istr;
  }



  std::ostream& Date::write(std::ostream& ostr) const {
    ostr.fill('0');
    ostr << year << "/";
    ostr.width(2);
    ostr << month << "/";
    ostr.width(2);
    ostr << day;
    return ostr;
  }

  std::ostream& operator << (std::ostream& o, Date& date) {
    date.write(o);
    return o;
  }

  std::istream& operator >> (std::istream& i, Date& date) {
    date.read(i);
    return i;
  }






}
