#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
Deck::Deck() 
: deck()
{
      for (Card::CardType C = Card::Pawn; C<= Card::Queen; C = static_cast<Card::CardType>(static_cast<int>(C)+1)){
        if(C != Card::Empty)
        {
        deck.push_back(new Card(C));
        deck.push_back(new Card(C));
        deck.push_back(new Card(C));
        deck.push_back(new Card(C));
        }
    }
}
Deck::Deck(int LvL) 
: deck()
{
    switch(LvL) {
        case 0:
        for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::King));
        }
        break;
        case 1:
        for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::Pawn));
        }
        break;
    
        case 2:
                for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::Knight));
        }
        break;
        
        
        case 3: 
                for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::Bishop));
        }
        break;
        case 4:
        for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::Rook));
        }
        break;
        case 5:
        for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::Queen));
        }
        break;
        
        case 6://8 Kings, 12 Rooks.
                for(int i = 0; i <= 7; i++){
        deck.push_back(new Card(Card::King));
        
        
        }
        for(int i = 0; i <= 11; i++){
        deck.push_back(new Card(Card::Rook));
        }
        break;
        
        case 7://5 kings, 6 knights, 6 bishops, 3 Queens; Total: 20
        
        deck.push_back(new Card(Card::King));
        deck.push_back(new Card(Card::King));
        deck.push_back(new Card(Card::King));
        deck.push_back(new Card(Card::King));
        deck.push_back(new Card(Card::King));
        
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Knight));
        break;
        case 8://Queen's Gambit - 10 Pawns, 2 Kings, 6 Queens, 2 Knights
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        deck.push_back(new Card(Card::Pawn));
        
        deck.push_back(new Card(Card::King));
        deck.push_back(new Card(Card::King));
        deck.push_back(new Card(Card::King));
        
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        deck.push_back(new Card(Card::Queen));
        
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        
        break;
        case 9://Three Point Party - 10 Bishops 10 Knights
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        deck.push_back(new Card(Card::Knight));
        
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        deck.push_back(new Card(Card::Bishop));
        
        break;
        case 10:
        std::cout << "\n\nLoading Custom Deck from 'deck.txt'...\n\n";
        processfile(myFile);
        break;

        default: 
        std::cout <<"\n\nerror loading Kings.\n\n";
                for(int i = 0; i <= 19; i++){
        deck.push_back(new Card(Card::King));
        }
        
    }
};
/*Deck::Deck() : owner_(owner) {
}*/
void Deck::processfile(const std::string& filename) {
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    char c;
    while (inputFile.get(c)) {
        // Process the character and output accordingly
        if (c == 'Q') {
            deck.push_back(new Card(Card::Queen));
        } else if (c == 'K') {
            deck.push_back(new Card(Card::King));
        } 
        else if (c == 'N') {
            deck.push_back(new Card(Card::Knight));
        }
        else if (c == 'P') {
         deck.push_back(new Card(Card::Pawn));   
        }
        else if (c == 'B') {
            deck.push_back(new Card(Card::Bishop));
        }
        else if (c == 'R') {
           deck.push_back(new Card(Card::Bishop));
        } else {
            std::cout << "Other character found\n";
        }
    }

    inputFile.close();
}
Card* Deck::TopCard()//look at top card.
{
	return deck.front();
}


Deck::~Deck()
{
	for (Card* card : deck)
	{
		delete card;
	}
	deck.clear();
}
void Deck::Shuffle() {
    	
	std::random_shuffle(deck.begin(), deck.end());
}

void Deck::Print()
{
	std::cout << "Deck Print \n\n" << std::endl;
	for (Card* card : deck)
	{
		std::cout << card->getCard();
		std::cout << " ";
	}
	std::cout <<"\nDeck Print End \n\n" << std::endl;
}


Card* Deck::drawCard() {
    if (!deck.empty()) {
        Card* card = deck.front();
        deck.pop_front();
        return card;
    }
    return nullptr;
}

