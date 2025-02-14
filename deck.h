#ifndef Deck_h
#define Deck_h

#include "card.h"
class Deck
{
private:
	Card myCards[52];
	int cardsDealt;

public:
	//Constructs a deck object with 52 cards.
	Deck();
	//Deals the first card in the deck
	Card deal();
	//Displays the full deck
	void displayDeck();
	//Randomizes card order
	void shuffle();
};
#endif

