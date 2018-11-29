//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/28
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>


#include "Good.h"

using namespace std;

namespace aid {


  void Good::name(const char* name) {

    if (name != nullptr) {

      int length = strlen(name);

      good_name = new char[length + 1];

      for (int i = 0; i < length; i++) {
        good_name[i] = name[i];
      }
      good_name[length] = '\0';
    }
    else if (name == nullptr) {
      delete[] good_name;
      good_name = nullptr;
    }


  }


  const char* Good::name() const {

    if (good_name != nullptr) {

      return good_name;
    }

    else {
      return nullptr;
    }


  }



  const char* Good::sku() const {

    return good_sku;
  }


  const char* Good::unit() const {

    return good_unit;
  }


  bool Good::taxed() const {

    return taxable;
  }




  double Good::itemPrice() const {

    return priceBeforeTax;
  }


  double Good::itemCost() const {

    if (taxable) {
      return itemPrice() * (1 + tax);
    }

    else {

      return itemPrice();
    }
  }


  void Good::message(const char* error) {

    if (error != nullptr) {
      error_state.message(error);
    }
  }


  bool Good::isClear() const {

    return error_state.isClear();
  }




  Good::Good(char type) {

    good_type = type;
    good_sku[0] = '\0';
    good_unit[0] = '\0';
    good_name = nullptr;
    quantity_hand = 0;
    quantity_need = 0;
    priceBeforeTax = 0.0;
    taxable = false;

  }


  Good::Good(const char* sku, const char* name1, const char* unit, int good, bool _tax, double price_before_tax, int need) {

    
    if (sku != nullptr && name1 != nullptr && unit != nullptr) {
      strncpy(good_sku, sku, strlen(sku));
      good_sku[strlen(sku)] = '\0';

      Good::name(name1);

      strncpy(good_unit, unit, strlen(unit));
      good_unit[strlen(unit)] = '\0';
    }
    quantity_hand = good;

    taxable = _tax;

    priceBeforeTax = price_before_tax;

    quantity_need = need;


  }



  Good::Good(const Good& obj) {

    *this = obj;
  }


  Good& Good::operator=(const Good& obj) {

    if (this != &obj) {

      good_type = obj.good_type;

      name(obj.good_name);

      strncpy(good_sku, obj.good_sku, strlen(obj.good_sku));
      good_sku[strlen(obj.good_sku)] = '\0';

      strncpy(good_unit, obj.good_unit, strlen(obj.good_unit));
      good_unit[strlen(obj.good_unit)] = '\0';

      quantity_hand = obj.quantity_hand;

      quantity_need = obj.quantity_need;

      priceBeforeTax = obj.priceBeforeTax;

      taxable = obj.taxable;




    }

    return *this;
  }


  Good::~Good() {

    delete[] good_name;
  }


  fstream& Good::store(fstream& file, bool newLine) const {

    file << good_type << "," << good_sku << "," << good_name << "," << good_unit << "," << taxable << "," << priceBeforeTax << "," << quantity_hand << "," << quantity_need;

    if (newLine) {

      file << endl;
    }

    return file;
  }


  fstream& Good::load(fstream& file) {

    char sku2[max_sku_length];
    char name2[max_name_length];
    char unit2[max_unit_length];
    double price2;
    int qty2;
    int needed2;
    char tax2;
    bool taxable2;

    if (file.is_open())
    {
      file.getline(sku2, max_sku_length, ',');
      sku2[strlen(sku2)] = '\0';

      file.getline(name2, max_name_length, ',');
      name2[strlen(name2)] = '\0';

      file.getline(unit2, max_unit_length, ',');
      unit2[strlen(unit2)] = '\0';

      file >> tax2;

      if (tax2 == '1')
        taxable2 = true;
      else if (tax2 == '0')
        taxable2 = false;

      file.ignore();

      file >> price2;
      file.ignore();

      file >> qty2;
      file.ignore();

      file >> needed2;
      file.ignore();

      *this = Good(sku2, name2, unit2, qty2, taxable2, price2, needed2);
    }

    return file;


  }



  ostream& Good::write(ostream& os, bool linear) const {

    if (!(error_state.isClear())) {
      os << error_state.message();
    }



    else if (linear) {

      os << setw(max_sku_length) << left << good_sku << "|" << setw(20) << left << good_name << "|" << setw(7) << right << fixed << setprecision(2) << itemCost() << "|"
        << setw(4) << right << quantity_hand << "|" << setw(10) << left << good_unit << "|" << setw(4) << right << quantity_need << "|";
    }

    else {

      os << " Sku: " << good_sku << endl << " Name (no spaces): " << good_name << endl << " Price: " << itemPrice() << endl;

      if (taxable) {

        os << " Price after tax: " << itemCost() << endl;
      }
      else {
        os << " Price after tax:  N/A" << endl;
      }

      os << " Quantity on Hand: " << quantity_hand << ' ' << good_unit << endl << " Quantity needed: " << quantity_need;
    }
  

      return os;
    
  }



  istream& Good::read(istream& is) {

    char* name_ = new char[max_name_length + 1];
    int qty_hand;
    int qty_need;
    double priceBefore;
    char tax_;



   if(!is.fail()) {
      cout << " Sku: ";
      is >> good_sku;
      cin.ignore();

      cout << " Name (no spaces): ";
      is >> name_;
      name(name_);
      

      cout << " Unit: ";
      is >> good_unit;
      cin.ignore();

      cout << " Taxed? (y/n): ";
      is >> tax_;

      if (!is.fail())
      {
        error_state.clear();

        if (tax_)
        {
          bool y_valid = tax_ == 'y' || tax_ == 'Y';
          bool n_valid = tax_ == 'n' || tax_ == 'N';

          if (y_valid) {
            taxable = true;
          }
          if (n_valid) {
            taxable = false;
          }
          if (!(y_valid || n_valid))
          {
            is.setstate(ios::failbit);
            error_state.message("Only (Y)es or (N)o are acceptable");
            return is;
          }
        }
      }
      else
      {
        is.setstate(ios::failbit);
        error_state.message("Only (Y)es or (N)o are acceptable");
        return is;
      }

      cout << " Price: ";
      is >> priceBefore;

      if (is.fail())
      {
        error_state.clear();
        is.setstate(ios::failbit);
        error_state.message("Invalid Price Entry");
        return is;
      }
      else {
        priceBeforeTax = priceBefore;
      }
        

      cout << " Quantity on hand: ";
      is >> qty_hand;
      cin.ignore();


      if (is.fail())
      {
        error_state.clear();
        error_state.message("Invalid Quantity Entry");
        is.setstate(ios::failbit);
        return is;
      }
      else
        quantity(qty_hand);

      cout << " Quantity needed: ";
      is >> qty_need;
      cin.ignore();

      if (is.fail())
      {
        error_state.clear();
        error_state.message("Invalid Quantity Needed Entry");
        is.setstate(ios::failbit);
        return is;
      }
      else {
        quantity_need = qty_need;
      }
      

      if (!is.fail())
      {
        error_state.clear();
      }
  }

  return is;
  }


  bool Good::operator==(const char* address) const {

    if (strcmp(address, good_sku) == 0) {
      return true;
    }

    else {
      return false;
    }

  }


  double Good::total_cost() const {

    return itemCost() * quantity();
  }

  void Good::quantity(int units) {

    quantity_hand = units;


  }


  bool Good::isEmpty() const {

    if (good_name == nullptr || good_name[0] == '\0') {

      return true;
    }

    else {
      return false;
    }
  }


  int Good::qtyNeeded() const {

    return quantity_need;
  }


  int Good::quantity() const {

    return quantity_hand;
  }


  bool Good::operator>(const char* address) const {

    if (strcmp(good_sku, address) > 0) {
      return true;
    }

    else {
      return false;
    }

  }


  bool Good::operator>(const iGood& obj) const {

    if (strcmp(good_name, obj.name()) > 0) {

      return true;
    }

    else {

      return false;
    }
  }


  int Good::operator+=(int num) {

    if (num > 0) {

      quantity_hand += num;
      
    }

    return quantity_hand;
  }


  ostream& operator<<(ostream& os, const iGood& obj) {

    return obj.write(os, true);
  }


  istream& operator>>(istream& is, iGood& obj) {

    return obj.read(is);
  }


  double operator+=(double& total, const iGood& obj) {

    return total + obj.total_cost();
  }



}