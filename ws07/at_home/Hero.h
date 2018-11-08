//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/09

#ifndef SICT_HERO_H_
#define SICT_HERO_H_

#include <iostream>

namespace sict {

  const int max_rounds = 100;

  class Hero {
    char name[41];
    int health;
    int attack;

  public:
    Hero();
    Hero(const char*, int, int);
    ~Hero();

    void operator-=(int);
    bool isAlive() const;
    int attackStrength() const;

    friend std::ostream& operator<<(std::ostream&, const Hero&);
  };

  const Hero& operator*(const Hero&, const Hero&); 
 
}

#endif
