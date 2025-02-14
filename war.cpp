// OneCardWar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Project Name: Prog 1 – One Card War
// Due Date February/13/2025
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <string>
#include "deck.h"
using namespace std;

int main()
{   
	Deck myDeck = Deck();
	string player1;
	string player2;

	//Starting sequence
	cout << "Enter the name of the first player: ";
	cin >> player1;
	cout << "Enter the name of the second player: ";
	cin >> player2;
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

	for (int i = 0; i < 26; i++)
	{
		Card p1c = myDeck.deal();
		Card p2c = myDeck.deal();

		cout << "GAME " << i+1 << endl;
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

	//Results
	cout << "------FINAL STATS------" << endl;
	cout << "       " << player1 << " VS " << player2<<endl;
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
	cout << "    " << ties;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
