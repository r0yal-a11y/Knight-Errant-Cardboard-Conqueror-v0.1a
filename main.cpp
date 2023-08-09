 /******************************************************************************
THIS IS THE CURRENT BUILD AND HAS NEW FEATURES REGARDING AI CONTROL
TODO: 
Make Deck IO
    - Make Level UI check Deck File
    - Make Deck UI Check Deck File
    - Refresh Deck after each Level
    
Make Game Loop Function
 - Card Placement Phase
 - Card Execution Phase
 - Check if Level is Complete
    => if Level is Complete, init() next level. 
Make Level UI 
    
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string>
#include <cstring>
#include <limits>
#include <vector>
#include <iomanip>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"
#include "CmdLine.h"
#include "Board.h"
#include "Util.h"


Board gameBoard;
bool debug = false;
  bool exitGame;
bool resetBoard = false;
CMDLine myLine(&gameBoard);

std::string ascii_art = 
"                        ██╗  ██╗███╗   ██╗██╗ ██████╗ ██╗  ██╗████████╗    ███████╗██████╗ ██████╗  █████╗ ███╗   ██╗████████╗                                    \n"
"                        ██║ ██╔╝████╗  ██║██║██╔════╝ ██║  ██║╚══██╔══╝    ██╔════╝██╔══██╗██╔══██╗██╔══██╗████╗  ██║╚══██╔══╝                                    \n"
"                        █████╔╝ ██╔██╗ ██║██║██║  ███╗███████║   ██║       █████╗  ██████╔╝██████╔╝███████║██╔██╗ ██║   ██║                                       \n"
"                        ██╔═██╗ ██║╚██╗██║██║██║   ██║██╔══██║   ██║       ██╔══╝  ██╔══██╗██╔══██╗██╔══██║██║╚██╗██║   ██║                                       \n"
"                        ██║  ██╗██║ ╚████║██║╚██████╔╝██║  ██║   ██║       ███████╗██║  ██║██║  ██║██║  ██║██║ ╚████║   ██║                                       \n"
"                        ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝                                       \n"
"                                                                                                                                                                 \n"
" ██████╗ █████╗ ██████╗ ██████╗       ██████╗  ██████╗  █████╗ ██████╗ ██████╗      ██████╗ ██████╗ ███╗   ██╗ ██████╗ ██╗   ██╗███████╗██████╗  ██████╗ ██████╗ \n"
"██╔════╝██╔══██╗██╔══██╗██╔══██╗      ██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██╔══██╗    ██╔════╝██╔═══██╗████╗  ██║██╔═══██╗██║   ██║██╔════╝██╔══██╗██╔═══██╗██╔══██╗\n"
"██║     ███████║██████╔╝██║  ██║█████╗██████╔╝██║   ██║███████║██████╔╝██║  ██║    ██║     ██║   ██║██╔██╗ ██║██║   ██║██║   ██║█████╗  ██████╔╝██║   ██║██████╔╝\n"
"██║     ██╔══██║██╔══██╗██║  ██║╚════╝██╔══██╗██║   ██║██╔══██║██╔══██╗██║  ██║    ██║     ██║   ██║██║╚██╗██║██║▄▄ ██║██║   ██║██╔══╝  ██╔══██╗██║   ██║██╔══██╗\n"
"╚██████╗██║  ██║██║  ██║██████╔╝      ██████╔╝╚██████╔╝██║  ██║██║  ██║██████╔╝    ╚██████╗╚██████╔╝██║ ╚████║╚██████╔╝╚██████╔╝███████╗██║  ██║╚██████╔╝██║  ██║\n"
" ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝       ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝      ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚══▀▀═╝  ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝\n"
"                                                                                                                                                                 ";
std::vector<std::string> MENU = {
    "This is a Simple Menu Prompt",
    "The Prompts will have a How to Play explanation",
    "A PLAY GAME Command",
    "A Check Custom Deck Command",
    "And a QUIT Command"
};

void PrintIntro(){
        
    std::cout << std::setw(100) <<  "The King has fallen..." 
    <<  std::endl << std::endl << std::setw(120)<<"The Kingdom of Chessia is Ruled by the cruel False King" << std::endl << std::endl << std::setw(100) << "Our only Hope is..."<< std::endl << std::endl << std::setw(150) <<
    ascii_art <<std::endl;
    ReadCheck();

    NewPage();
    
}
std::vector<std::string> KEY = {
        "|        KEY         |",
        "|____________________|",
        "|              |     |",
        "|     Empty    |     |",
        "|              |     |",
        "|====================|",
        "|              |     |",
        "|    Player    |  ⟁  |",
        "|              |     |",
        "|====================|",
        "|              |     |",
        "|    Depot     |  ♙  |",
        "|              |     |",
        "|====================|",
        "|              |     |",
        "|    CopyCat   |O___O|",
        "|              |     |",
        "|====================|",
        "|              |     |",
        "|     Duck     | ~o~ |",
        "|              |^^^^^|",
        "|====================|",
        "|              |  |  |",
        "|  Wanderer    |-[o]-|",
        "|              |  |  |",
        "|====================|",
        "|              |  |  |",
        "| WandererDest |-[ ]-|",
        "|              |  |  |",
        "|====================|",
        "|          Left|<-o  |",
        "|  Guard       |-----|",
        "|         Right|  o->|",
        "|====================|",
        "______________________"
    };//size: 0 -> 33 = 34
//function to display the current board state.
void GUIOutput(Board myG_Board, Hand& myG_Hand, CMDLine& myG_Line) {
    std::vector<std::string> BoardGUI = myG_Board.BrdOutput();
    std::vector<std::string> HandGUI_0 = myG_Hand.hand_Card(0);
     std::vector<std::string> HandGUI_1 = myG_Hand.hand_Card(1);
      std::vector<std::string> HandGUI_2 = myG_Hand.hand_Card(2);
       std::vector<std::string> HandGUI_3 = myG_Hand.hand_Card(3);
    std::vector<std::string> LineGUI_0 = myG_Line.getLineGui(0);
    std::vector<std::string> LineGUI_1 = myG_Line.getLineGui(1);
    std::vector<std::string> LineGUI_2 = myG_Line.getLineGui(2);
    std::vector<std::string> LineGUI_3 = myG_Line.getLineGui(3);
    //Spacer Line is 
    std::string CMDLINE = "      P L A N             F I R S T                  P L A N                         W E L L \t\t";
    std::string SPACER = "                                                                                              \t\t";
    std::string LABEL  = "|         0           |          1            |            2          |           3           |\t\t";
 std::string TOPOFHAND = "|_____________________________________________________________________________________________|\t\t";
 std::string HAND      = "|           K N O W L E D G E      F R O M       T H E        F A L L E N                     |\t\t";
 if(debug == true){
       std::cout << "LineGUI_0 size: " << LineGUI_0.size() << std::endl;
    std::cout << "LineGUI_1 size: " << LineGUI_1.size() << std::endl;
    std::cout << "LineGUI_2 size: " << LineGUI_2.size() << std::endl;
    std::cout << "LineGUI_3 size: " << LineGUI_3.size() << std::endl;
 }
    
     std::cout<<"\n____________________________________________________________________________________________________________________________________________________________________________\n";
     std::cout<< CMDLINE << std::endl;
     std::cout<< LABEL << std::endl;
   std::cout << TOPOFHAND << std::endl;
   
    for(int i = 0; i < LineGUI_0.size(); ++i){
        std::cout<< LineGUI_0[i] << " ! " << LineGUI_1[i] <<" ! " << LineGUI_2[i] << " ! " << LineGUI_3[i] << "\t\t"<< BoardGUI[i] << KEY[i] << std::endl;
    }
    int LineCounter1 = LineGUI_0.size();
    int LineCounter2 = LineCounter1 + 9;
    for(int i = LineCounter1; i < LineCounter2-2; ++i){
       std::cout<< SPACER <<BoardGUI[i] << KEY[i] << "\n";
    }
    std::cout << HAND << BoardGUI[LineCounter2-2] << KEY[LineCounter2-2] << "\n";
    std::cout<< TOPOFHAND << BoardGUI[LineCounter2-1] << KEY[LineCounter2-1] << "\n";
    for(int i = 0; i < HandGUI_0.size(); ++i){
    std::cout<<  HandGUI_0[i] << "   " << HandGUI_1[i] <<"   " << HandGUI_2[i] << "   " << HandGUI_3[i] << "\t\t"<< BoardGUI[LineCounter2+i] << KEY[LineCounter2+i] << std::endl;
    }
 
}
// Function to display the main menu and get the level from the user
int getLevelFromUser() {
    int level;
    

    std::cout << "PCES - the Recommended kings of PCES You should bring to this level. These are more recommendations, and not requirements.\n";
    std::cout <<  std::setw(30) << "Enter the LvL number to play a level!" <<std::endl;

    std::cout << "          TUTORIAL LEVELS                " << std::setw(12) << "LvL - the number you should enter if you want to play the LeveL." <<std::endl;
    std::cout << "=========================================" << std::setw(12)<< "PCES - the Recommended kinds of PCES You should bring to this level."<<  std::endl;
    std::cout << "|LvL|   NAME   | PCES |  Description    |" << std::setw(12) << "Description - A description of the level."<<std::endl;
    std::cout << "=========================================" <<std::endl;
    std::cout << "| 0 |  Tutorial  |  ♔  | King   Movement |" << std::endl;
    std::cout << "| 1 |  Tutorial  |  ♟︎  | Pawn   Movement |" << std::endl;
    std::cout << "| 2 |  Tutorial  |  ♘  | Knight Movement |" << std::endl;
    std::cout << "| 3 |  Tutorial  |  ♝  | Bishop Movement |" << std::endl;
    std::cout << "| 4 |  Tutorial  |  ♜  | Rook   Movement |" << std::endl;
    std::cout << "| 5 |  Tutorial  |  ♕  | Queen  Movement |" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "                        DEFAULT  LEVELS                                            " << std::endl;
    std::cout << "============================================================================================" << std::endl;
    std::cout << "| 6 |  1st Raid  | ♔♝  | Move across the 4 corners of the Board   to take supplies       | "  << std::endl;
    std::cout << "|___|____________|_______|__________________________________________________________________|" << std::endl;
    std::cout << "| 7 |  CopyCat   | ♘    | Eliminate the Pieces with a CopyCat to help you                  | " << std::endl;
    std::cout << "|___|____________|_______|__________________________________________________________________|" << std::endl;
    std::cout << "| 8 | Two Fronts | ♘ ♘ | Use the CopyCat to attack 2 sides of the map at once!            |" <<std::endl;
    std::cout << "|___|____________|_______|__________________________________________________________________|" << std::endl;
    std::cout << "| 9 | Patrols    | ????  | Guards are on the Lookout! Beware their attacks!                 |" <<std::endl;
    std::cout << "|___|____________|_______|__________________________________________________________________|" << std::endl;
    std::cout << "| 10| Duck       | ????  | Defeat the enemies, but mind the Duck! the Duck will block your  |" <<std::endl;
    std::cout << "|___|____________|_______|__________________________________________________________________|" << std::endl;
    std::cout << "| 11| Wanderer   | ????  | A Bounty has been put on your head! Avoid the Wanderer's         |" <<std::endl;//always moves towards last spot 
    std::cout << "|   |            |       | Teleportation magics or face utter annihilation!                 |" << std::endl;
    std::cout << "|___|____________|_______|__________________________________________________________________|" << std::endl;
    std::cout << "| 12|  Showdown  | ???   | It's all come down to this. The False King is sending everything |" <<std::endl;//Protecting a Piece?
    std::cout << "|   |            | ???   | he's got to eliminate you. Think you can handle it?              |" <<std::endl;
    std::cout << "============================================================================================"<<std::endl;
    std::cout << " Which Level Would you like to play? ";
    std::cin >> level; 
    return level;
}
int DeathCounter = 0;
// Function to display the deck menu and get the deck choice from the user
int getDeckChoiceFromUser(int levelChoice) {
    int deckChoice;
        char answer;
    if(levelChoice <6){//if the level is a tutorial level (LT 5), skip the deckChoice menu and continue. 
        std::cout<< "Initializing deck "<< levelChoice << " for Tutorial LvL " << levelChoice;
        return levelChoice;
    }
    
    std::cout << "===== Deck Menu =====" << std::endl;
    
    std::cout << "      DECK SELECTION   " << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << "| Deck# |    Name        |Size|     Description                          |" << std::endl;
    std::cout << "==========================================================================" <<std::endl;
    std::cout << "|~~ 1 ~~| Line King      | 20 | 8 Kings, 12 Rooks                        |" << std::endl;
    std::cout << "|~~ 2 ~~| Royal Court    | 20 | 5 kings, 6 knights, 6 bishops, 3 Queens  |" << std::endl;
    std::cout << "|~~ 3 ~~| Queen's Gambit | 20 |  10 Pawns, 2 Kings, 6 Queens, 2 Knights  |" << std::endl;
    std::cout << "|~~ 4 ~~| 3-Point Party  | 20 | 10 Knights, 10 Bishops                   |" << std::endl;
    std::cout << "|===========================================|" << std::endl;
    std::cout << "|~~ 5 ~~| Load Custom Deck from file.       |" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "Input the Deck Number of your choice: ";
    std::cin >> deckChoice;
    int dChoice = deckChoice + 5;
    Deck DisplayDeck(dChoice);
    DisplayDeck.Print();
    std::cout << "\nis this the deck you'd like to use?(y/n)\n";

    std::cin >> answer;
    if((answer == 'Y') || (answer == 'y'))
    {
        return dChoice;
       
    }
    else 
    //current glitch: deck memory overflows and infinite loops because there is no deletion. Need to fix. 
    return getDeckChoiceFromUser(levelChoice);
}
int GetCardPlacings(Hand& Player_Hand, CMDLine& myLine){//Gets an integer and places cards on the line. Simple enough. 
            if(gameBoard.LevelFailed() == true){
                return 0;
            }
    char P_input;
    if(debug == true) 
    {
        std::cout << "\n\nStarting the Card Placement function\n\n";
    }
    std::cout << "\n Would you like to place some cards from your hand onto the Command Line? \n" << std::endl
    <<std::setw(80) << "( Y | Place Cards on Command Line" << std::endl << std::setw(80) << " N | Continue to Action Phase " << std::endl 
    <<std::setw(80) << "( E | exit Game. " << std::endl << "\t\t\t\t\t\t\t\t\t\t >";
    std::cin >> P_input;
    if(P_input == 'n' || P_input == 'N'){
        return 0;
    }
    if(P_input == 'e' || P_input == 'E'){
       exitGame = true; 
       std::cout << "\n\n\n\n\n \t\t\t\t\t\t\t\t\t GOOD BYE";
       
       return 0;
    }
    if(P_input == 'r' || P_input == 'R'){
        resetBoard = true;
        std::cout << "\n\n\n\n\n \t\t\t\t\t\t\t\t\t GOOD BYE";
        return 0;
    }

    if(debug == true)
        {
            std::cout << "\n\nStart of GetCard Placings | Hand Size:"<< Player_Hand.cards_.size() <<" Card 0: " <<Player_Hand.cards_[0]->getCard() 
            <<" Card 1: " << Player_Hand.cards_[1]->getCard() <<"        Card 2: " <<Player_Hand.cards_[2]->getCard() <<" Card 3: " <<Player_Hand.cards_[3]->getCard() <<std::endl;
        }
        int Card_Selection = -1;
        int Card_Destination = -1;
        std::cout << "\n\t\t\t\t\tPLANNING"<<std::endl<<"\n\t\t\t\tEnter a Number from 0 to 3 to select a Card from your hand. Enter 4 to play all cards in your hand."<< std::endl << "\t\t\t\t\t\t";
        
        std::cin >> Card_Selection;
        if(Card_Selection > -1 && Card_Selection < Player_Hand.cards_.size()){
            std::cout <<"\nEnter a Number from 0 to 3 to select a Destination for your Card. ";
            std::cin >> Card_Destination;
            if(Card_Destination >-1 && Card_Destination < 4){
            myLine.PlayCard(Player_Hand.cards_[Card_Selection], Card_Destination);
            Player_Hand.removeCard(Card_Selection);
            }
        }
        else if( Card_Selection = 4){
            for(int i = Player_Hand.cards_.size() - 1; i >= 0; i--){

               // std::cout <<"\nMOVING  "<< Player_Hand.cards_[i]->getCard() << " to " << 3 - i;
                myLine.PlayCard(Player_Hand.cards_[i], 3-i);
                Player_Hand.removeCard(i);
            }
        }
        else
        {
            std::cout << "\nError: Invalid Number output\n";
            return 1;
        }
        
        int HandSize = Player_Hand.cards_.size();
        if(HandSize == 0){
            return 0;
        }
        else return 1;
        
    }
    

// Function to initialize the game with the selected level and deck
void initializeGame(int level, int deckChoice) {
    // Initialize the board with the selected level
    exitGame = false;
    gameBoard.reset();
    bool PawnLevelFailed = false;
    gameBoard.init(level);
    myLine.Clear();

    // Initialize the deck with the selected choice
    Deck myDeck(deckChoice);
    if(debug == true){
        myDeck.Print();
    }
    Hand myHand(&myDeck);
    int TurnCounter = 0;
    while(gameBoard.LevelClear() == false && gameBoard.LevelFailed() == false){
        
        if(debug == true){
            std::cout << "Shuffling 2 Times" << std::endl << std::endl;
            myDeck.Shuffle();
        myDeck.Shuffle();
        }
        else{
        myDeck.Shuffle();
        myDeck.Shuffle();
            
        }
         myHand.addCard(); myHand.addCard(); myHand.addCard();  myHand.addCard();

        do
        
        {
        //Check if Board has been reset;
        
        PrintHint(level);
        std::cout << "\t\t\t\t\t\t\t\tDay  #: " << TurnCounter << " Opponents Left: " << gameBoard.opponents << std::endl;
            GUIOutput(gameBoard, myHand, myLine); 
            std::cout << "Day  #: " << TurnCounter << " Opponents Left: " << gameBoard.opponents << std::endl;
            
            
        }while(GetCardPlacings(myHand, myLine) != 0 && gameBoard.LevelFailed() == false && gameBoard.LevelClear() == false);
        if(exitGame == true)
        {
            return;
        }
        GUIOutput(gameBoard, myHand, myLine);
        if(gameBoard.LevelFailed() != true && gameBoard.LevelClear() != true){
        myLine.Execute();
        if(level == 1 && myLine.moved == false){
            return;
        }
        }
  
        if(gameBoard.LevelFailed() == true){
            std::cout << "Level Failed. Remember that Pawns can only attack diagonally and move if and only if there is no one in front of them.";
            return;
        }
        std::cout << "\t\t\t\t\t\t\t\tDay #" << TurnCounter <<" Has Ended.\n\n";
        ReadCheck();
        //TEST ME 
        //gameBoard.doEnemyAIMoves();
        //gameBoard.doAllyAIMoves();
        //if(gameBoard.Ducks >0){
        //gameBoard.moveDuck();
        //}
        
        ++TurnCounter;
        
    }  
    if(gameBoard.LevelClear() == true)
    {
        std::cout << "\n\n\nAll Opponents Defeated! Would you like to continue to the next level?(y/n)";
    char answer;
    std::cin >> answer;
    if(answer == 'y'){
        if(level < 5){
           
            initializeGame(level + 1, level + 1);
        }
        if(level == 5){
            std::cout << "Please Select a Deck before continuing to your first Raid\n";
            ReadCheck();
            
            initializeGame(level + 1, getDeckChoiceFromUser(12) );//int doesnt matter here because it doesnt modify it in any way.
        }
        if(level == 12){
            std::cout << "You've avenged your King. The tyranny of the False King has ended. \nThe Kingdom of Chessia will rebuild. \n YOU WON";
            gameBoard.reset();
            ReadCheck();
            return;
        }
        gameBoard.reset();
        initializeGame(level + 1, deckChoice);

    }
    if(answer == 'n'){
            std::cout << "Quitting game;";
            ReadCheck();
    return;
    }
    

        
    }
    if(gameBoard.LevelFailed() == true) {
        std::cout << "You have failed.";
        return;
    }
    // gameLoop(gameBoard, myDeck);
};
void HowToPlay() {
    int ReturnValue;

    std::cout << std::setw(50) << "How To Play..." << std::endl;
    std::cout << ascii_art;

    std::cout << std::setw(60) << "\n\n\n\nPlace Cards on the Command Line from your Hand by typing the corresponding number into the prompt.\n"
              << std::setw(63) << "Eliminate all Depots, Wanderers, and Guards to proceed to the next level.\n"
              << std::setw(57) << "The Player will always move first.\n"
              << std::setw(54) << "Depots are stationary targets, often defended by other pieces.\n"
              << std::setw(53) << "Take Enemy Pieces by moving on top of them.\n"
              << std::setw(59) << "The Command Line will execute after you finish placing your Action Cards. It executes from left to right.\n"
              << std::setw(63) << "Placing a Card on an occupied slot will replace that card. Be careful to not run out of cards.\n"
              << std::setw(75) << "CopyCats will move to the opposite position of the Player. (ie, if a Player moves to (C,2), the CopyCat will from wherever it is to the opposite of the Player.\n"
              << std::setw(55) << "Use this to do attack from all fronts!\n"
              << std::setw(62) << "Guards move back and forth across a row. They can take CopyCats and Knight-Errants.\n"
              << std::setw(59) << "Wanderers will teleport to the WandererDestination after each time an Action slot is executed. This will happen.\n"
              << std::setw(59) << "Make Sure you arent standing on a Wanderer's Destination, or they'll cash in the bounty!" << std::endl << std::endl;
               std::cout << std::setw(53) << "Press Enter to Continue...";
                 std::cin.get();


};

    

   

    
    

int Menu(){
    int PlayerReady;
    for(int i = 0; i <= 25; i++){
        std::cout << std::endl;
    }

        std::cout << std::setw(100)<< ascii_art << std::endl
        << std::endl<< std::endl<< std::endl;
         std::cout << std::setw(100)<< "        ===== Main Menu =====" << std::endl;
        std::cout << std::setw(93)<< "Press 1 to Begin" << std::endl;
        std::cout << std::setw(100)<<"Press 2 for How to Play" << std::endl;
        std::cout << std::setw(93) <<"Press 3 to Exit"<< std::endl << std::endl<< std::endl<< std::endl<< std::endl;;
        std::cout << std::setw(90) << ">";
        std::cin >> PlayerReady;
        switch(PlayerReady){
            case 1:
            std::cout << std::setw(50) << "Beginning";
            
            return 1;
            case 2:

           
            return 2;
            case 3:
            std::cout << "GoodBye, Knight!";
            return 0;
        }
    };





int main()
{
    PrintIntro();
    int MenuOP;
    do {
        MenuOP = Menu();
        std::cin.get();
        if(MenuOP == 1){
            //GET LEVEL
            int level = getLevelFromUser();
            //GET DECK
            int decknum = getDeckChoiceFromUser(level);
            //GAMELOOP
            initializeGame(level, decknum);
        }
        if(MenuOP == 2){
        HowToPlay();
        }
    }while(MenuOP!= 0);

    return 0;
}
