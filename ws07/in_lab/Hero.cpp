//Student name: Seung Ho Nam
//Student number: 148151178
//Date: 2018/11/05

#include <iostream>
#include <cstring>
#include "Hero.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

  Hero::Hero() {
    
    name[0] = '\0';
    health = 0;
    attack = 0;

  }

  Hero::Hero(const char* m_name, int m_health, int m_attack) {

    if (m_name[0] != '\0' && m_health > 0 && m_attack > 0) {
      strncpy(name, m_name, 41);
      name[40] = '\0';

      health = m_health;
      attack = m_attack;
    }

    else {
      Hero();
    }
  }


  Hero::~Hero() {

  }


  void Hero::operator-=(int m_attack) {

    if (m_attack > 0) {
      health -= m_attack;

      if (health < 0) {
        health = 0;
      }
    }
  }



  bool Hero::isAlive() const {
    if (health > 0) {
      return true;
    }
    else {
      return false;
    }
  }

  int Hero::attackStrength() const {
    
    if (name[0] == '\0' && attack == 0) {
      return 0;
    }
    else {
      return attack;
    }
  }




  ostream& operator<<(ostream& os, const Hero& hero) {


    if (hero.name[0] != '\0' && hero.attack != 0) {

      for (unsigned int i = 0; i < strlen(hero.name); i++) {

        os << hero.name[i];

      }
      return os;
    }
    else {
      os << "No hero" << endl;
      return os;
    }
  }



  const Hero& operator*(const Hero& first, const Hero& second) {

    cout << "Ancient Battle! " << first << " vs " << second << " : ";

    Hero F, S;
    F = first;
    S = second;

    int a1 = F.attackStrength();
    int a2 = S.attackStrength();

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