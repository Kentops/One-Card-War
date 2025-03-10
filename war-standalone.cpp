
#include <iostream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

class Card
{
private:
	char suit;
	char rank;

public:
	//Constructor for cards
	Card(char mySuit, char myRank)
	{
		suit = mySuit;
		rank = myRank;
	}

	//Displays the card as a string output
	void displayCard()
	{
		string displayedRank{ rank };

		if (rank == 'T')
		{
			displayedRank = "10";
		}

		cout << displayedRank << suit;
	}

	//Compares two card ranks. Returns 1 if this crad is highter,
	//0 for a tie, and -1 when the other card is higher.
	int compareCard(Card other)
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
};

class Deck
{
private:
	vector <Card> myCards;
public:
	//Constructs a deck object with 52 cards.
	Deck()
	{
		//Get a random seed
		srand(time(0));
		//Generate deck
		char suits[] = { 'C','S','D','H' };
		char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				myCards.push_back( Card(suits[i], ranks[j])) ;
			}
		}

	}

	//Deals the next card in the deck.
	//Throw an exception if the deck is empty
	Card deal()
	{
		if (myCards.size() > 0)
		{
			Card output = myCards[0];
			myCards.erase(myCards.begin());
			return output;
		}
		else
		{
			throw 404;
		}
	}

	//Displays the full deck
	void displayDeck()
	{
		//Just going to assume no new suits or ranks are introduced.
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
	void shuffle()
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
};

int main()
{
	Deck myDeck = Deck();
	string player1;
	string player2;
	string tempGames;
	int games;

	//Starting sequence
	cout << "Enter the name of the first player: ";
	cin >> player1;
	cout << "Enter the name of the second player: ";
	cin >> player2;
	cout << "How many games will they play? ";
	cin >> tempGames;
	games = stoi(tempGames);
	cout << endl << "ORIGINAL DECK" << endl;
	myDeck.displayDeck();
	myDeck.shuffle();
	cout << endl << "SHUFFLED DECK" << endl;
	myDeck.displayDeck();
	cout << endl;

	//Game loop - Playing rounds of war
	int p1wins = 0;
	int p2wins = 0;
	int ties = 0;

	try 
	{
		for (int i = 0; i < games; i++)
		{
			Card p1c = myDeck.deal();
			Card p2c = myDeck.deal();

			cout << "GAME " << i + 1 << endl;
			cout << "--------" << endl;
			cout << player1 << "=> ";
			p1c.displayCard();
			cout << endl << player2 << "=> ";
			p2c.displayCard();
			cout << endl;

			if (p1c.compareCard(p2c) == 1)
			{
				p1wins++;
				cout << player1 << "=> WINNER";
			}
			else if (p1c.compareCard(p2c) == -1)
			{
				p2wins++;
				cout << player2 << "=> WINNER";
			}
			else // Tie
			{
				ties++;
				cout << "TIE GAME";
			}
			cout << endl << endl;
		}
	}
	catch (int x)
	{
		cout << "Error - Deck is Empty!" << endl << endl;
	}
	
	//Results
	cout << "------FINAL STATS------" << endl;
	cout << "       " << player1 << " VS " << player2 << endl;
	cout << "WINS   " << p1wins;

	//Getting spacing right
	//Not using a method because the rubric says not to
	if (p1wins >= 10)
	{
		int spaces = player1.length() - 2;
		for (int i = 0; i < spaces; i++)
		{
			cout << ' ';
		}
	}
	else
	{
		int spaces = player1.length() - 1;
		for (int i = 0; i < spaces; i++)
		{
			cout << ' ';
		}
	}
	cout << "    " << p2wins << endl;
	cout << "LOSSES " << p2wins;
	if (p2wins >= 10)
	{
		int spaces = player1.length() - 2;
		for (int i = 0; i < spaces; i++)
		{
			cout << ' ';
		}
	}
	else
	{
		int spaces = player1.length() - 1;
		for (int i = 0; i < spaces; i++)
		{
			cout << ' ';
		}
	}
	cout << "    " << p1wins << endl;
	cout << "TIES   " << ties;
	if (ties >= 10)
	{
		int spaces = player1.length() - 2;
		for (int i = 0; i < spaces; i++)
		{
			cout << ' ';
		}
	}
	else
	{
		int spaces = player1.length() - 1;
		for (int i = 0; i < spaces; i++)
		{
			cout << ' ';
		}
	}
	cout << "    " << ties << endl;
}