// TODO: add file header comments here
/* Name: Seung Ho Nam
   Student ID: shnam
   shnam@myseneca.ca
   workshop 4
   */
// TODO: add your headers here
#include "Passenger.h"
#include <iostream>
#include <cstring>
using namespace std;

// TODO: continue your namespace here
namespace sict {

  // TODO: implement the default constructor here
  Passenger::Passenger() {
    passengerName[0] = '\0';
    destination[0] = '\0';
    yearOfDeparture = 0;
    monthOfDeparture = 0;
    dayOfDeparture = 0;

  }


  // TODO: implement the constructor with 2 parameters here
  Passenger::Passenger(const char* pname, const char* destin, int y, int m, int d) {
    if (pname == nullptr || pname == '\0' || destin == nullptr || destin == '\0' || y >= 2021 || y <= 2017 || m >= 13 || m <= 0 || d >= 32 || d <= 0) {
      passengerName[0] = '\0';
      destination[0] = '\0';

    }
    else {

      strncpy(passengerName, pname, strlen(pname) + 1);
      passengerName[18] = '\0';
      strncpy(destination, destin, strlen(destin) + 1);
      destination[18] = '\0';
      yearOfDeparture = y;
      monthOfDeparture = m;
      dayOfDeparture = d;
    }
  }

  // TODO: implement isEmpty query here
  bool Passenger::isEmpty() const {
    if (strlen(passengerName) == 0 || strlen(destination) == 0) {
      return true;
    }
    else {
      return false;
    }
  }
  // TODO: implement display query here
  void Passenger::display() const {
    if (isEmpty()) {
      cout << "No passenger!" << endl;
    }
    else {
      cout << passengerName << " - " << destination << " on " << yearOfDeparture << "/";
      cout.fill('0');
      cout.width(2);
      cout << monthOfDeparture << "/";
      cout.fill('0');
      cout.width(2);
      cout << dayOfDeparture << endl;

    }
  }

  const char* Passenger::name() const {
    return this->passengerName;
  }

  bool Passenger::canTravelWith(const Passenger& a) const {
    if (strcmp(this->destination, a.destination) == 0 && this->yearOfDeparture == a.yearOfDeparture && this->monthOfDeparture == a.monthOfDeparture && this->dayOfDeparture == a.dayOfDeparture) {
      return true;
    }
    else {
      return false;
    }
  }
  
  Passenger::Passenger(const char* pname, const char* destin) {
    if (pname == nullptr || pname == '\0' || destin == nullptr || destin == '\0') {
      passengerName[0] = '\0';
      destination[0] = '\0';

    }
    else {
      strncpy(passengerName, pname, strlen(pname) + 1);
      passengerName[18] = '\0';
      strncpy(destination, destin, strlen(destin) + 1);
      destination[18] = '\0';
      yearOfDeparture = 2018;
      monthOfDeparture = 10;
      dayOfDeparture = 1;

    }
  }
}