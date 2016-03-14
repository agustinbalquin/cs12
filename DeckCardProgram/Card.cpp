#include <iostream>
using namespace std;
class Card {
 private:
    char suit;
    int rank;
 public:

    /* Assigns a default value of 2 of Clubs
    */
    Card();


    /* Assigns the Card the suit and rank provided.
       suits: c = Clubs, d = Diamonds, h = Hearts, s = Spades
       If an invalid suit is provided, sets the suit to Clubs
       ranks: 1 - 13 (1 = Ace, 11 = Jack, 12 = Queen, 13 = King)
       If an invalid rank is provided, sets the rank to 2
       Accepts lower or upper case characters for suit
    */  
    Card(char, int);


    /* Returns the Card's suit
    */
    char getSuit() const;


    /* Returns the Card's rank as an integer
    */
    int getRank() const;

    /* Outputs a Card in the following format: Rank of Suit
       For example, if the rank is 3 and the suit is h: 3 of Hearts
       Or, if the rank is 1 and the suit is d: Ace of Diamonds
       Or, if the rank is 12 and the suit is c: Queen of Clubs
       etc.
    */  
    friend ostream & operator<<(ostream &, const Card &);
};


/////////
/////////
/////////




#include "Card.h"
//#include "Deck.h"
#ifndef C_H
#define C_H
Card::Card() {
    suit = 'c';
    rank = 2;
    
}

Card::Card(char x, int y) {
    
    suit = x;
    rank = y;
    
    if (rank > 13 || rank < 1) {
        rank = 2;
    }
    if (suit == 'C' || suit == 'c') {
        suit = 'c';
    }
    else if (suit == 'H' || suit == 'h') {
        suit = 'h';
    }
    else if (suit == 'D' || suit == 'd') {
        suit = 'd';
    }
    else if (suit == 'S' || suit == 's') {
        suit = 's';
    }
    else {
        suit = 'c';
    }

    // if (x != 'c' || x != 'd' || x != 'h' || x != 's' ) {
    //     suit = 'c';
    // }

}

char Card::getSuit() const {
    
    return suit;
}

int Card::getRank() const {
    
    return rank;
}

ostream & operator<<(ostream &out, const Card &cd) {
    
    if (cd.rank == 11) {
        out << "Jack of ";
    }
    if (cd.rank == 12) {
        out << "Queen of ";
    }
    if (cd.rank == 13) {
        out << "King of ";
    }
    if (cd.rank == 1) {
        out << "Ace of ";
    }
    if (cd.rank <= 10 && cd.rank > 1) {
        out << cd.rank << " of ";
    }
    if (cd.suit == 'c') {
    out << "Clubs";  
    }
    if (cd.suit == 'd') {
    out << "Diamonds";  
    }
    if (cd.suit == 'h') {
    out << "Hearts";  
    }
    if (cd.suit == 's') {
    out << "Spades";  
    }
	return out;
}

#endif