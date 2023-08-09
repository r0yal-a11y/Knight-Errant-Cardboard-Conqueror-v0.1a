#include "CmdLine.h"
#include "Card.h"
#include "Board.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include "Util.h"
//#include "Board.h"
//#include "Piece.h"
CMDLine::CMDLine() : myLine() {
    //initialize myPiece to the Playerpiece. 
    myLine.push_back(new Card(Card::Empty));
        myLine.push_back(new Card(Card::Empty));
        myLine.push_back(new Card(Card::Empty));
        myLine.push_back(new Card(Card::Empty));

}
CMDLine::CMDLine(Board* board) : myLine(), GameBoard(board) {
    
    //initialize the line's cards to EMPTY
     myLine.push_back(new Card(Card::Empty));
        myLine.push_back(new Card(Card::Empty));
        myLine.push_back(new Card(Card::Empty));
        myLine.push_back(new Card(Card::Empty));
    //set myPiece to the current position. 
    

}
std::vector<std::string> CMDLine::getLineGui(int index) {
    if (index >= 0 && index < myLine.size()) {
        myLine[index]->Print();
        return myLine[index]->myCard;
    } else {
        // Handle the case where index is out of bounds
        return {
            "|       EMPTY       |",
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
}


CMDLine::~CMDLine() {
    for(int i = 0; i <= 3; i++) {
        delete myLine[i];
    }
}
void CMDLine::ExecuteCard(int i){
       
    // Get a list of valid moves for the card at index i in the command line
    std::vector<std::pair<int, int>> valid_moves = GameBoard->getValidMoves(myLine[i]);

    // Check if there are any valid moves available
    if (valid_moves.size() > 0) {
        moved = true;
        int it = 0;

        // Display the card that is currently being moved
        std::cout << "\n\tCurrently Moving as \n\t\t" << myLine[i]->getCard();
        std::cout << "\nValid Destinations: {Destination #} {( Row | Col ) \n";

        // Display the valid destination positions for the current card
        for (const auto& position : valid_moves) {
            std::cout << std::setw(7) << it 
            << " (" << num_to_Char(position.second) << position.first << ") \t";
            it = it + 1;
        }

        int input;
        std::cout << "\nDesired Destination:  ";

        // Get the desired destination input from the player
        std::cin >> input;

        // Check if the input is within the valid range of destinations
        if ((input >= 0) && (input < valid_moves.size())) {
            // Check if the destination is occupied by a duck
            if (GameBoard->isDuck(valid_moves[input].first, valid_moves[input].second) == true) {
                std::cout << "\n\nQUACKED! YOU MOVED INTO THE DUCK! LOSE YOUR MOVE\n\n";
                return;
            } else {
                // Move the player's piece to the selected position on the game board
                GameBoard->movePlayerPiece(valid_moves[input].first, valid_moves[input].second);
            }
        } else {
            // Handle the case where the input is not a valid move and prompt again
            std::cout << input << " is not a valid move. \n";
            ExecuteCard(i);
        }
    }
}



void CMDLine::Execute() {//function pulls a series of paired ints that correspond to positions that are valid. 

    std::string ExecuteNotif = "\n\nExecuting Battle Plan. First Card at Slot 0 of Your CommandLine\n";
    bool moveMade = false;
    int noMoveCounter = 0;
    for(int i = 0; i < 4; i++){
       
        if(GameBoard->LevelFailed() == true){
           std::cout<< "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYou have been defeated!\n\n\t\t\t\t\t\t\t\t\t\t\t       GAMEOVER\n\n\n\n\n\n";

            break;
        }
        if(GameBoard->LevelClear() == true){
            std::cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tBOARD     WIPED\n\n\t\t\t\t\t\t\t\t\t\t\t       WELL DONE KNIGHT!\n\n\n\n\n\n";
            break;
        }
        if(myLine[i]->type_ != Card::Empty){
            ExecuteCard(i);//Execute the Cards

            if(moved == false){
                ++noMoveCounter;
                if(noMoveCounter == 4){
                    //delete Player Piece??
                    GameBoard->PawnLevelFailed = true;
                    return;
                }
            }
        }

        if(GameBoard->Wanderers > 0 ){
            std::cout << "Wanderers Take their Turn" << std::endl;
            GameBoard->moveWanderers();//Move the Wanderers
            GameBoard->setWandererDestination();
        }
        if(GameBoard->Guards > 0){
            std::cout << "Guards Continue their Patrol..." << std::endl;
            GameBoard->moveGuards();//Move the Guards
        }
        GameBoard->display();
        
    }
    if(GameBoard->Ducks > 0 ){// Duck moves after all moves have been executed.
            std::cout << "The Flock has Moved!" << std::endl;
            GameBoard->moveDuck();//Move the Duck
        }
        GameBoard->display();
   if(GameBoard->LevelFailed() == true){
           std::cout<< "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tYou have been defeated!\n\n\t\t\t\t\t\t\t\t\t\t\t       GAMEOVER\n\n\n\n\n\n";

            return;
        }
        if(GameBoard->LevelClear() == true){
            std::cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tBOARD     WIPED\n\n\t\t\t\t\t\t\t\t\t\t\t       WELL DONE KNIGHT!\n\n\n\n\n\n";
            return;
        }
}
   /* for(Card* card : myLine){
        
        1. iterate through the Cammond Line, 2. get a list of valid moves, 2.1receive movement from Player, 2.2Move Player Piece if legal,
        //3 Do AI moves
        //case: CopyCat: move CopyCat
        move Wanderer
        move VIP
        all pieces are blocked by DUCK
        
        move DUCK
        then check if the game is done. 
        
        
        std::vector<std::pair<int,int>> valid_moves = GameBoard->getValidMoves(card);//function returns a list of valid moves.
        
        if(GameBoard->getValidMoves(card).size() > 0)
        
        {
            int it = 0;
            std::cout << "\n\tCurrently Moving as \n\t\t"<<card->getCard();
            std::cout << "\nValid Destinations: ( Row | Col ) \n";
            for(const auto& position : valid_moves) {
                
                std::cout  << it << " ("<< num_to_Char(position.second)  << position.first << ") \t";
                it = it+1;
                
               
                
                
            }
        
    
        int i;
        std::cout<<"\nDesired Destination:  ";
        std::cin >> i;

        if((i >= 0) && (i <= valid_moves.size())){
            //Player Moves first
                 GameBoard->movePlayerPiece(valid_moves[i].first, valid_moves[i].second);
        //All movements are handled by the Gameboard. DONT DO THEM IN CMDLINE
        //doCopyCat - output updated Gameboard
        //doVIP - output updated Gameboard /.jn
        //doAIMoves() - output updated Gameboard for each move.
            

        }
        else {
                std::cout << i << " is not a valid move. \n";
            }
            GameBoard->display();
            continue;
        
        }
        

        }
        if(GameBoard->LevelClear()){
                std::cout <<"\n Level Finished! \n";
            }
}*/
void CMDLine::doAIMoves() {//DEPRECATED NOT NEEDED
    doCopyCatMoves();
    doWanderMoves();
    
}
void CMDLine::doCopyCatMoves(){
 std::cout << "Doing CopyCatMoves\n";   

 //Checks the current move selected
 //Swaps the Row and Column values
 //moves the CopyCat to the new value;
}
void CMDLine::doWanderMoves(){
    //Moves Wanderer to teh Destination;
    MoveWanderertoDestination();
    //makes a new Wanderer Destination;
    makeNewWandererDestination();
};
void CMDLine::MoveWanderertoDestination() {
    std::cout <<"Moving Wanderer to Destination\n";
    //just moves the Wanderer to the Destination;
}
//moves the Destination to wherever it needs to be. Randomly set
void CMDLine::makeNewWandererDestination() {
    //
    std::cout <<"Making New WandererDest\n";
}


//could move this inside. Will do later. 
            
char CMDLine::num_to_Char(int num){
    char t;
    switch(num) {
        case 0 :
        t = 'A';
        break;
        case 1 : 
        t = 'B';
        break;
        case 2 :
         t = 'C';
        break;
        case 3:
         t = 'D';
        break;
        case 4:
         t = 'E';
        break;
        case 5:
         t = 'F';
        break;
        case 6: t='G';
        case 7: t='H';
        default:
        break;
    }
    return t;
}

Card* CMDLine::GetCard(int index) {
    return this->myLine[index];
}
//might need print for later. but will make do?
void CMDLine::Print() {
    std::cout << "\n\tCMDLINE  \n";
    std::cout<<"|---   ----||---   ---||---   ---||---   ---|\n|  ";
    for(Card* card : myLine){
        
         std::cout<<card->getCard();
         std::cout<< "   || ";
    }
    std::cout<<"\n|---[0]---||---[1]---||---[2]---||---[3]---|\n\n";
    
}

void CMDLine::PlayCard(Card* handCard, int LineIndex) {
    Card* LineCard = handCard;
    myLine.erase(myLine.begin() + LineIndex);
    myLine.insert(myLine.begin() + LineIndex, LineCard);
    
    
    
    
    
          //myLine[LineIndex] = LineCard;
        //  delete handCard;
}
void CMDLine::Clear() {
    for (Card* card : myLine) {
        delete card;
    }
    myLine.clear();
    myLine.push_back(new Card(Card::Empty));
    myLine.push_back(new Card(Card::Empty));
    myLine.push_back(new Card(Card::Empty));
    myLine.push_back(new Card(Card::Empty));
}
//Card* CMD_Line::GetCard(int LineIndex)