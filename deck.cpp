#include "deck.h"
#include "card.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

//Constructs a deck object with 52 cards.
Deck::Deck()
{
	//Get a random seed
	srand(time(0));
	//Generate deck and initialize variables
	cardsDealt = 0;
	char suits[] = { 'C','S','D','H' };
	char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };

	for (int i = 0; i < sizeof(suits) / sizeof(suits[0]); i++)
	{
		for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); j++)
		{
			myCards[(sizeof(ranks) / sizeof(ranks[0]) * i) + j] = Card(suits[i], ranks[j]);
		}
	}

}

//Deals the next card in the deck
Card Deck::deal()
{
	cardsDealt++;
	return myCards[cardsDealt - 1];
}

//Displays the full deck
void Deck::displayDeck()
{
	//Just going to assume no new suits or ranks are introduced this time.
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			myCards[(13 * i) + j].displayCard();
			if (j != 12)
			{
				cout << ",";
			}
		}
		//End of suit
		cout << endl;
	}
}

//Randomizes card order
void Deck::shuffle()
{
	//I once had to do a deck shuffle in Java for High School.
	//I'm going to swap two cards' positions 500 times. This can
	//result in the card not moving, but so can normal shuffling.
	for (int i = 0; i < 500; i++)
	{
		int indexA = rand() % 52;
		int indexB = rand() % 52;
		Card temp = myCards[indexA];
		myCards[indexA] = myCards[indexB];
		myCards[indexB] = temp;
	}
}