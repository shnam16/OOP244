/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date 09/17/2018
// Author Seung Ho Nam
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


#include <iostream>
#include "Kingdom.h"
using namespace std;

namespace sict {
 
  void display(Kingdom &a) {
    cout << a.m_name << ", " << "population " << a.m_population << endl;
  }
}