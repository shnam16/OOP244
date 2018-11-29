// Final Project Milestone 1
//
// Version 1.0
// Date 2018/11/28
// Author Seung Ho Nam
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Seung Ho Nam              Date 2018/11/28                Reason
/////////////////////////////////////////////////////////////////
//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/28
#include "Date.h"
#include <iostream>

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

    else if (y <= 2018 && m <= 11 ) {
      errCode(PAST_ERROR);
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


  std::istream& Date::read(std::istream& istr)
  {
    char slash;

    errCode(NO_ERROR);
    istr >> year >> slash >> month >> slash >> day;

    if (istr.fail())
    {

      *this = Date();
      errCode(CIN_FAILED);

    }
    
    if (year < min_year || year > max_year) {

      *this = Date();
      errCode(YEAR_ERROR);
    }

    else if (month < 1 || month > 12) {

      *this = Date();
      errCode(MON_ERROR);
    }
    else if (day > mdays(month, year)) {
      
      *this = Date();
      errCode(DAY_ERROR);
    }
    else if (year <= 2018 && month <= 11) {
      *this = Date();
      errCode(PAST_ERROR);
    }

    istr.clear();
    return istr;

  }



  std::ostream& Date::write(std::ostream& ostr) const {
    ostr << year << "/";
    if (month < 10) {
      ostr << "0" << month << "/";
    }
    else {
      ostr << month << "/";
    }

    if (day < 10) {
      ostr << "0" << day;
    }
    else {
      ostr << day;
    }

    return ostr;
  }

  std::ostream& operator << (std::ostream& o, const Date& date) {
    date.write(o);
    return o;
  }

  std::istream& operator >> (std::istream& i, Date& date) {
    date.read(i);
    return i;
  }






}
