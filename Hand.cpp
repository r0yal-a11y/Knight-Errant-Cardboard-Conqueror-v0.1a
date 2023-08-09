#include "Hand.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


Hand::Hand(Deck* deck) : cards_(), deck_(deck) {
    // Initialize the hand with an empty vector of cards
}

bool Hand::isFull() const {
    return cards_.size() >= MAX_HAND_SIZE;
}

void Hand::addCard() {
    if (!isFull()) {
        Card* card = deck_->drawCard();
        cards_.push_back(card);
    }
}

void Hand::removeCard(int index) {
    if (index >= 0 && index < 5) {
        cards_.erase(cards_.begin() + index);
    }
}

Card* Hand::GetCard(int index) const {
    if ((index >= 0) && (index < 5)) {
        return cards_[index];
    }
    return nullptr;
}

std::vector<std::string> Hand::hand_Card(int index){
    std::vector<std::string> Line_Card;
    if(index < cards_.size()){
        cards_[index]->Print();
        Line_Card = cards_[index]->myCard;
    }
    else
    {
        Line_Card = {"|       EMPTY       |",
            "|___________________|",
            "|    ___________    |",
            "|    |         |    |",
            "|    |         |    |",
            "|    |    X    |    |",
            "|    |         |    |",
            "|    |_________|    |",
            "|___________________|",
            "|   Slot is Empty   |",
            "|Place  a Card Here |",
            "|To  Move your Piece|",
            "|___________________|",
            };
    }

    return Line_Card;
    
}
void Hand::ShowHand() {
    std::cout<<"\n\t\tHAND";
     std::cout<<"\n||---[0]---||---[1]---||---[2]---||---[3]---||\n||  ";
    for(Card* card : cards_) {
        if(card->getCard() == "Unknown" ){
            std::cout << " Unkown ";
        }
        else if (card->getCard() == "Empty");
        else
        {
        std::cout << card->getCard();
		std::cout<< "   ||  ";
        }
    }
    std::cout<<"\n||---[0]---||---[1]---||---[2]---||---[3]---||\n\n";
    std::cout<<"\n";
}
int Hand::getCardCount() const {
    return cards_.size();
}