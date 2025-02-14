#include <string>
#include <iostream>
#include <string>
#include "card.h"
using namespace std;

//Constructor for cards
Card::Card(char mySuit, char myRank)
{
	suit = mySuit;
	rank = myRank;
}

//default Constructor for arrays
Card::Card()
{
	suit = 0;
	rank = 0;
}

//Displays the card as a string output
void Card::displayCard()
{
	string displayedRank{ rank };
	
	if (rank == 'T')
	{
		displayedRank = "10";
	}
	else if (rank == 1)
	{
		displayedRank = "A";
	}

	cout << displayedRank << suit;
}

//Compares two card ranks. Returns 1 if this crad is highter,
//0 for a tie, and -1 when the other card is higher.
int Card::compareCard(Card other)
{
	char ranks[13] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
	int myIntRank = 0, otherIntRank = 0;
	//Set ranks as integers
	for (int i = 0; i < 13; i++)
	{
		if (rank == ranks[i])
		{
			myIntRank = i;
		}
		if (other.rank == ranks[i])
		{
			otherIntRank = i;
		}
	}

	if (myIntRank > otherIntRank)
	{
		return 1;
	}
	else if (myIntRank == otherIntRank)
	{
		return 0;
	}
	else //Other card's rank is higher
	{
		return -1;
	}
}