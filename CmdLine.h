#ifndef CMDLINE_H
#define CMDLINE_H
#include <iostream>
#include <vector>
#include <string>
#include "Hand.h"
#include "Card.h"
#include "Board.h"
#include "Util.h"
class CMDLine  {
    public:
    CMDLine();   // makes a cmdline 
    
    //makes a commandline connected to a board.
    CMDLine(Board* board);
    //deletes a commandline.
    ~CMDLine();
    
    // runs a series of checks and prompts the player with positions they could move their piece to. 1,2,3,4 then again once prompted.
    void Execute(); 
    //returns a pointer to a Card at index 
    virtual Card* GetCard(int index);
    
    virtual void Print();// Prints the Cards on CmdLine;
    
    virtual void PlayCard(Card* card, int index);
    
    std::vector<std::string> getLineGui(int index);    //returns the vector of strings for the card at slot i
    
    void Clear();
    char num_to_Char(int num);
    void ExecuteCard(int i);
    void Commit();
    
     std::pair<int, int> FindCopyCatPosition();
     void MimicPlayerMoves();
     void doAIMoves();//
        void doDuckMoves();
        void doCopyCatMoves();
        void doColumnBlockerMoves();
        void doRowBlockerMoves();
        void doWanderMoves();
            void MoveWanderertoDestination();
            void makeNewWandererDestination();
    //bool functions allow Execute to skip if they are present.

    bool moved = false;
    std::vector<Card*> myLine;
    Deck* CL_Deck;
    Hand* CL_Hand;
    Board* GameBoard;
};
#endif