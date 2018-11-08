//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/09

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include <iostream>
#include "Hero.h"

namespace sict {

  class SuperHero : public Hero {
    int bonus;
    int defense;

  public:
    SuperHero();
    SuperHero(const char*, int, int, int, int);
    ~SuperHero();

    int attackStrength() const;
    int defend() const;
  };

  const SuperHero& operator*(const SuperHero&, const SuperHero&);
}

#endif // SICT_SUPERHERO_H
