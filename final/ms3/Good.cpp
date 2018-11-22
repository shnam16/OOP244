//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/21
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Error.h"
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


  }


  const char* Good::name() const {

    if (good_name != nullptr || good_name[0] != '\0') {

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

    error_state.message(error);
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


    strncpy(good_sku, sku, max_sku_length);
    good_sku[max_sku_length] = '\0';

    name(name1);

    strncpy(good_unit, unit, max_unit_length);
    good_unit[max_unit_length] = '\0';

    quantity_hand = good;
    
    taxable = _tax;

    priceBeforeTax = price_before_tax;

    quantity_need = need;

    
  }



  Good::Good(const Good& obj) {

    name(obj.good_name);

    good_type = obj.good_type;

    strncpy(good_sku, obj.good_sku, max_sku_length);
    good_sku[max_sku_length] = '\0';

    strncpy(good_unit, obj.good_unit, max_unit_length);
    good_unit[max_unit_length] = '\0';

    quantity_hand = obj.quantity_hand;

    quantity_need = obj.quantity_need;

    priceBeforeTax = obj.priceBeforeTax;

    taxable = obj.taxable;
  }


  Good& Good::operator=(const Good& obj) {

    if (this != &obj) {

      good_type = obj.good_type;

      strncpy(good_sku, obj.good_sku, max_sku_length);
      good_sku[max_sku_length] = '\0';

      strncpy(good_unit, obj.good_unit, max_unit_length);
      good_unit[max_unit_length] = '\0';

      quantity_hand = obj.quantity_hand;

      quantity_need = obj.quantity_need;

      priceBeforeTax = obj.priceBeforeTax;

      taxable = obj.taxable;

      delete[] good_name;

      name(obj.good_name);
    }

    return *this;
  }


  Good::~Good() {

    delete[] good_name;
  }


  fstream& Good::store(fstream& file, bool newLine) const {

    file << good_type << "," << good_sku << "," << good_unit << "," << good_name << "," << quantity_hand << "," << quantity_need << "," << priceBeforeTax << "," << taxable;

    if (newLine) {
      
      file << endl;
    }
    
    return file;
  }


  fstream& Good::load(fstream& file) {

    Good temp;
    temp.good_name = new char[max_name_length + 1];

    if (file.is_open()) {

      file >> temp.good_type >> temp.good_sku >> temp.good_unit >> temp.good_name >> temp.quantity_hand >> temp.quantity_need >> temp.priceBeforeTax >> temp.taxable;
      *this = temp;
    }

    delete[] temp.good_name;
    temp.good_name = nullptr;

    return file;

  }



  ostream& Good::write(ostream& os, bool linear) const{

    if (linear) {

      os << setw(max_sku_length) << left << good_sku << "|" << setw(20) << left << good_name << "|" << setw(7) << setprecision(2) << fixed << right << itemCost() << "|"
        << setw(4) << right << quantity_hand << "|" << setw(10) << left << good_unit << "|" << setw(4) << right << quantity_need << "|";
    }

    else {

      os << "Sku: " << good_sku << endl << "Name: " << good_name << endl << "Price: " << itemPrice() << endl;

      if (taxed()) {

        os << "Price after tax: " << itemCost() << endl;
      }
      else {
        os << "N/A" << endl;
      }

      os << "Quantity on hand: " << quantity_hand << endl << "Quantity needed: " << quantity_need << endl;
    }

    return os;

  }



  istream& Good::read(istream& is) {

    char sku_[max_sku_length + 1];
    char* name_ = new char[max_name_length + 1];
    char unit_[max_unit_length];
    int qty_hand;
    int qty_need;
    double priceBefore;
    char tax_;
    bool taxable_;


    cout << " Sku: ";
    is >> sku_;

    cout << " Name (no spaces): ";
    is >> name_;

    cout << " Unit: ";
    is >> unit_;

    cout << " Taxed? (y/n): ";
    is >> tax_;
    if (tax_ == 'Y' || tax_ == 'y') {
      taxable_ = true;

    }

    else if (tax_ == 'N' || tax_ == 'n') {
      taxable_ = false;
    }

    else {
      is.setstate(ios::failbit);
      error_state.message("Only (Y)es or (N)o are acceptable");
    }

    if (!is.fail()) {
      cout << " Price: ";
      is >> priceBefore;
      if (is.fail()) {
        error_state.message("Invalid Price Entry");
      }
    }

    if (!is.fail()) {
      cout << " Quantity on hand: ";
      is >> qty_hand;

      if (is.fail()) {
        error_state.message("Invalid Qunatity Entry");
      }
    }


    if (!is.fail()) {
      cout << " Quantity needed: ";
      is >> qty_need;

      if (is.fail()) {
        error_state.message("Invlid Quantity Needed Entry");
      }
    }


    if (!is.fail()) {
      *this = Good(sku_, name_, unit_, qty_hand, taxable_, priceBefore, qty_need);
    }

    delete[] name_;
    name_ = nullptr;

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


  bool Good::operator>(const Good& obj) const {

    if (strcmp(good_name, obj.good_name) > 0) {

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


  ostream& operator<<(ostream& os, const Good& obj) {

    return obj.write(os, true);
  }


  istream& operator>>(istream& is, Good& obj) {

    return obj.read(is);
  }


  double operator+=(double& total, const Good& obj) {

    return total + obj.total_cost();
  }



}