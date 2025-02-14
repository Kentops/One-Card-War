#ifndef Card_h
#define Card_h
class Card
{
private:
	char suit;
	char rank;

public:
	//Just declare that these are functions that can be called.

	//Constructor for cards
	Card(char mySuit, char myRank);

	//default Constructor for arrays
	Card();

	//Displays the card as a string output
	void displayCard();

	//Compares two card ranks. Returns 1 if this card is highter,
	//0 for a tie, and -1 when the other card is higher.
	int compareCard(Card other);

};
#endif

