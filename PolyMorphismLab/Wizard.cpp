#ifndef __WIZ___
#define __WIZ___
using namespace std;

#include <iostream>
#include "Character.h"


class Wizard : public Character {
    
    protected:
        
        int rank;
    
    
    public:
        Wizard(const string &name, double health, double attackStrength, int rank);
        
        void attack(Character &);
    
    
    
};

#endif



/////
/////
/////


#include "Wizard.h"
#include <iostream>
using namespace std;
#include "Character.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
:Character(WIZARD, name, health, attackStrength), rank(rank) {}


void Wizard::attack(Character &opponent) {
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        
        double damage = (attackStrength) * ((this-> rank * 1.0) / opp.rank);
        opp.setHealth(opp.getHealth() - damage);
        cout << "Wizard " << this->name << " attacks " << opp.name << " --- POOF!!" << endl;
        cout << opp.name << " takes " << damage << " damage." << endl;
        
    }
    else {
        double damage = attackStrength;
        opponent.setHealth(opponent.getHealth() - damage);
        cout << "Wizard " << this->name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
          
    }
    
}