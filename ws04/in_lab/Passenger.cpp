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

  }

  // TODO: implement the constructor with 2 parameters here
  Passenger::Passenger(const char* pname, const char* destin) {
    if (pname == nullptr || pname == '\0' || destin == nullptr || destin == '\0') {
      passengerName[0] = '\0';
      destination[0] = '\0';
    }
    else {
     
      strncpy(passengerName, pname, strlen(pname)+1);
      passengerName[18] = '\0';
      strncpy(destination, destin, strlen(destin)+1);
      destination[18] = '\0';
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
      cout << passengerName << " - " << destination << endl;
    }
  }
}