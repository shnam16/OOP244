//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/28

#ifndef AID_PERISHABLE_H
#define AID_PERISHABLE_H

#include "Date.h"
#include "Good.h"
#include <iostream>


namespace aid {

  class Perishable : public Good {
    
    Date expiry_date;
    
  public:
    Perishable();
    std::fstream& store(std::fstream& file, bool newLine = true) const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear) const;
    std::istream& read(std::istream& is);
    const Date& expiry() const;


  };
  
  iGood* CreatePerishable();
 

}
#endif // !AID_PERISHABLE_H

