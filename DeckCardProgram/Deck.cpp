
#ifndef C_H
#define C_H
#include <vector>
#include "Card.h"
using namespace std;

class Deck {
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:
    /* Constructs a Deck of 52 cards:
       Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King of each suit.
       Cards should start off in this order with the order of suits being:
       Clubs, Diamonds, Hearts, Spades.
    */
    Deck();

    /* Deals (returns) the top card on the deck. 
       Removes this card from theDeck and places it in the dealtCards.
    */
    Card dealCard();

    
    /* Places all cards back into theDeck and shuffles them into random order.
    */
    void shuffleDeck();


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned deckSize() const;

};

#endif





/////
/////
/////


#include "Deck.h"

#include <cstdlib>
#include <algorithm>
Deck::Deck() {
    char temp = 's';
    for (int i = 51; i >= 0; i--) {
        theDeck.push_back(Card( temp,((i % 13)+ 1) ));
        //cout << Card( temp, ((i% 13)+ 1) ) <<  " ";
        if (i < 40) {
            temp = 'h';
        }
        if (i < 27) {
            temp = 'd';
        }
        if (i < 14) {
            temp = 'c';
        }
    }
}


Card Deck::dealCard(){
    
    Card temp = theDeck.at(theDeck.size() - 1);
    theDeck.pop_back();
    dealtCards.push_back(temp);
    return temp;
}

void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); i++) {
        theDeck.push_back(dealtCards.at(i));
        
    }
    dealtCards.clear();
    //cout << theDeck.size();
    // int check = 52;
    // for (int i = 0; i < check; i++) {
    //     swap(theDeck.at(i), theDeck.at(rand() % 52));
    // }
    random_shuffle(theDeck.begin(), theDeck.end()); 

}


unsigned Deck::deckSize() const {
    
    return theDeck.size();
}

