#include <vector>
#include <string>
#include <iostream>
#include "Card.h"
#include "Deck.h"

//#include "Player.h"
#ifndef HAND_H
#define HAND_H
class Hand {
public:
    Hand(Deck* deck);
    Hand() {};
    ~Hand() {};
   virtual  bool isFull() const;
    virtual void addCard();
    virtual void removeCard(int index);
    virtual Card* GetCard(int index) const;
    virtual void ShowHand();
    int getCardCount() const;
    std::vector<std::string> hand_Card(int index);
    std::vector<Card*> cards_;
    Deck* deck_;
    static const int MAX_HAND_SIZE = 4;
   //Player* player;
};
#endif



