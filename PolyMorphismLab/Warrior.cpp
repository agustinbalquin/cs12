#ifndef __WARR__
#define __WARR__

using namespace std;
#include <iostream>
#include "Character.h"


class Warrior : public Character {
    
    private:
        
        string allegiance;
    
    public:
    
        Warrior(const string &name, double health, double attackStrength, string org);
    
        
        void attack(Character &);
        
    
};

#endif

/////
/////
/////


#include "Warrior.h"
#include <iostream>


Warrior::Warrior(const string &name, double health, double attackStrength, string org)
:Character(WARRIOR, name, health, attackStrength) ,allegiance(org)
{}

    
    
void Warrior::attack(Character &opponent) {

    if (opponent.getType() == WARRIOR) {

        Warrior &opp = dynamic_cast<Warrior &>(opponent);

        if(opp.allegiance == this-> allegiance) {

            cout << "Warrior " << this->name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }

        else {

            double damage = (this-> health / MAX_HEALTH) * (this-> attackStrength);
            opponent.setHealth(opponent.getHealth()- damage);
            cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
            cout << opponent.getName() << " takes " << damage << " damage." << endl;

        }
    }

    else {
        
        double damage = (this-> health / MAX_HEALTH) * (this-> attackStrength);
        opponent.setHealth(opponent.getHealth()- damage);
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;

    }
    
}
    