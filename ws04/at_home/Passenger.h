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
    int yearOfDeparture;
    int monthOfDeparture;
    int dayOfDeparture;

  public:
    Passenger();
    Passenger(const char* a, const char* b);
    Passenger(const char* pname, const char* destin, int y, int m, int d);
    bool isEmpty() const;
    void display() const;
    const char* name() const;
    bool canTravelWith(const Passenger&) const;
  };
}
#endif