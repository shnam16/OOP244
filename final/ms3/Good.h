//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/21

#ifndef AID_GOOD_H
#define AID_GOOD_H

#include "Error.h"


namespace aid {

  const int max_sku_length = 7;
  const int max_unit_length = 10;
  const int max_name_length = 75;
  const double tax = 0.13;

  class Good {
    
    char good_type;
    char good_sku[max_sku_length + 1];
    char good_unit[max_unit_length + 1];
    char* good_name;

    int quantity_hand;
    int quantity_need;

    double priceBeforeTax;
    
    bool taxable;

    Error error_state;


  protected:

    void name(const char* name);
    const char* name() const;
    const char* sku() const;
    const char* unit() const;
    bool taxed() const;
    double itemPrice() const;
    double itemCost() const;
    void message(const char* error);
    bool isClear() const;

  public:


    Good(char type = 'N');
    Good(const char* sku, const char* name1, const char* unit, int good = 0, bool _tax = true, double price_before_tax = 0.0, int need = 0);
    Good(const Good& obj);
    
    Good& operator=(const Good& obj);

    ~Good();

    std::fstream& store(std::fstream& file, bool newLine = true) const;
    std::fstream& load(std::fstream& file);

    std::ostream& write(std::ostream& os, bool linear) const;

    std::istream& read(std::istream& is);

    bool operator==(const char*) const;

    double total_cost() const;
    void quantity(int);
    bool isEmpty() const;
    int qtyNeeded() const;
    int quantity() const;
    bool operator>(const char*) const;
    bool operator>(const Good&) const;
    int operator+=(int);


  };


  std::ostream& operator<<(std::ostream&, const Good&);
  std::istream& operator>>(std::istream&, Good&);
  double operator+=(double&, const Good&);
}








#endif
