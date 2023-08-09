
#include <vector>
#include <deque>
#include <list>
#include <string>
#include "Card.h"

#pragma once
class Deck
{
public:
	Deck();//construct
	~Deck();//destruct
	//Deck(int i);

	virtual void Print();
	void Shuffle();
	Card* drawCard();
	Card* TopCard();//look at top card.
	void PopCard();//card goes from top to bottom
	//Card* DrawOne(int, Deck);
	//Card* Discard(int, Deck, Deck);
	
	
	//debug function for unit testing.
	//0.7.0 - added a function for creating a specific deck for a specific level.
    void processfile(const std::string& filename);
    std::string myFile = "deck.txt";
	Deck(int LvL);
    //Load_DeckFile();
	std::deque<Card*> deck;//pointer gives dynamic polymorph

};