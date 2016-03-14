#ifndef __Char_H_
#define __Char_H_
using namespace std;
#include <iostream>

enum CharType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
    CharType type;
    string name;
    double health;
    double attackStrength;

 public:
     Character(CharType type, const string &name, double health, double attackStrength);
     CharType getType() const;
     const string & getName() const;
     /* Returns the whole number of the health value (static_cast to int). */
     int getHealth() const;
     void setHealth(double h);
     /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
     bool isAlive() const;
     virtual void attack(Character &) = 0;
 };
 
#endif



 /////
 /////
 /////


#include "Character.h"

#include <iostream>

using namespace std;





     Character::Character(CharType type, const string &name, double health, double attackStrength) 
     : type(type), name(name), health(health), attackStrength(attackStrength){
            
         
     }
     
     CharType Character::getType() const {
         return type;
     }
     
     const string & Character::getName() const {
         return name;
     }
     /* Returns the whole number of the health value (static_cast to int). */
     
     int Character::getHealth() const {
         return health;
     }
     
     void Character::setHealth(double h) {
         this->health = h;
     }
     /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
     
     bool Character::isAlive() const {
         if (this->health <= 0 ) {
             return false;
         }
         return true;
     }


