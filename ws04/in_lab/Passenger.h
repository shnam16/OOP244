// TODO: add file header comments here
/* Name: Seung Ho Nam
   Student ID: shnam
   shnam@myseneca.ca
   workshop 4
   */
// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {
  // TODO: define the Passenger class here

  class Passenger {
    char passengerName[19];
    char destination[19];

  public:
    Passenger();
    Passenger(const char* pname, const char* destin);
    bool isEmpty() const;
    void display() const;
  };
}
#endif