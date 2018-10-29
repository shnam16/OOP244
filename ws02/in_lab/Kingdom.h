/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
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


#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


namespace sict {
 
  struct Kingdom {
    char m_name[32];
    int m_population;
  };

  void display(Kingdom &a);
}
#endif