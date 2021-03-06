#ifndef __ELF_H__
#define __ELF_H__

using namespace std;
#include <iostream>
#include "Character.h"


class Elf : public Character {
    
    private:
        
        string family;
        
        
    public:
        Elf(const string &name, double health, double attackStrength, string org);
        
        void attack(Character &);
    
    
    
};

#endif

//////
//////
//////




#include "Elf.h"
#include <iostream>
using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, string org)
: Character(ELF, name, health, attackStrength) , family(org)
{
    
    
    
    
}
    

void Elf::attack(Character &opponent) {

    if (opponent.getType() == ELF) {
        
        Elf &opp = dynamic_cast<Elf &>(opponent);

        if(opp.family == this-> family) {
            cout << "Elf " << this->name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }

        else {

            double damage = (this-> health / MAX_HEALTH) * (this-> attackStrength);
        
            opponent.setHealth(opponent.getHealth() - damage);
            cout << "Elf " << this-> name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
            cout << opponent.getName() << " takes " << damage << " damage." << endl;
        }
    }

    else {
        
        double damage = (this-> health / MAX_HEALTH) * (this-> attackStrength);
        
        opponent.setHealth(opponent.getHealth() - damage);
        cout << "Elf " << this-> name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << damage << " damage." << endl;

    }
   
}





