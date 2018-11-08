//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/09

#include <iostream>
#include <cstring>
#include "Hero.h"
#include "SuperHero.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

namespace sict {

  SuperHero::SuperHero() :Hero() {
    bonus = 0;
    defense = 0;
  }

  SuperHero::SuperHero(const char* m_name, int m_health, int m_attack, int m_bonus, int m_defense) : Hero(m_name, m_health, m_attack) {
    bonus = m_bonus;
    defense = m_defense;
  }

  SuperHero::~SuperHero(){

  }

  int SuperHero::attackStrength() const {
    int a = Hero::attackStrength();

    if (a != 0) {
      a += bonus;
    }

    return a;
  }


  int SuperHero::defend() const {
    if (defense != 0) {
      return defense;
    }
    else {
      return 0;
    }
  }


  const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {

    cout << "Super Fight! " << first << " vs " << second << " : ";

    SuperHero F, S;

    F = first;
    S = second;

    int a1 = F.attackStrength() - S.defend();
    int a2 = S.attackStrength() - F.defend();

    for (int i = 0; i < max_rounds; i++) {
      F -= a2;
      S -= a1;

      if (!F.isAlive() && !S.isAlive()) {
        cout << "Winner is " << first << " in " << i + 1 << " rounds." << endl;
        return first;
        break;
      }

      else if (!F.isAlive()) {
        cout << "Winner is " << second << " in " << i + 1 << " rounds." << endl;
        return second;
        break;
      }

      else if (!S.isAlive()) {
        cout << "Winner is " << first << " in " << i + 1 << " rounds." << endl;
        return first;
        break;
      }
    }

    cout << "Winner is " << first << " in " << max_rounds << " rounds." << endl;
    return first;
  }

}