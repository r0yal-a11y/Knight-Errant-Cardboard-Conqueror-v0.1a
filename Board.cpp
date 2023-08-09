#include "Board.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <utility>
Board::Board() {
    grid = std::vector<std::vector<Piece>>(ROWS, std::vector<Piece>(COLS, {Piece::Type::Empty}));
};
//to make a new level, copy paste this, rename it to the level, and add a new case function to the SelectLevel function in the GameHandler.cpp file. 
Board::~Board() {
 /*       for (auto& row : grid) {
            for (auto& piece : row) {
                delete &piece;
            }
        }*/
        grid.clear();
    }

void Board::initialize() {
    // Set the Player piece at a specific position
    std::cout <<" Picked initialize???";
    int playerRow = 4;
    int playerCol = 4;
    grid[playerRow][playerCol].type = Piece::Type::Player;

    // Set Opponent pieces at specific positions
    std::vector<std::pair<int, int>> opponentPositions = {
        {1, 2}, {3, 3}, {4, 1} // Add more positions as needed
    };

    for (const auto& position : opponentPositions) {
        int opponentRow = position.first;
        int opponentCol = position.second;
        grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
    }
    opponents = opponentPositions.size();
}
void Board::init(int myLevel){
    int Lvl = myLevel;
    if( Lvl == 0){//King Tutorial
        int playerRow = 1;
        int playerCol = 1;
        grid[playerRow][playerCol].type = Piece::Type::Player;
    
        // Set Opponent pieces at specific positions
        std::vector<std::pair<int, int>> opponentPositions = {
            {0, 0}, {0, 1}, {0, 2}, {0,3}
             // Add more positions as needed
        };
    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        return;
    }
    else if( Lvl == 1)//Pawn Tutorial
    { 
         int playerRow = 4;
        int playerCol = 4;
        grid[playerRow][playerCol].type = Piece::Type::Player;
    
        // Set Opponent pieces at specific positions
        std::vector<std::pair<int, int>> opponentPositions = {
            {2, 2}, {3, 3}, {1, 3}// Add more positions as needed
        };
    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        return;
    }
    
    else if( Lvl == 2)//Knight Tutorial - NOT DEVELOPED YET
    {
int playerRow = 5;
        int playerCol = 0;
        grid[playerRow][playerCol].type = Piece::Type::Player;
    
        // Set Opponent pieces at specific positions
        std::vector<std::pair<int, int>> opponentPositions = {
            {4, 2}, {3, 3}, {0, 1} // Add more positions as needed
        };
    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        return;
    }
    else if(Lvl == 3){//Bishop Tutorial
int pRow = 4;
        int pCol = 4;
        grid[pRow][pCol] = Piece::Type::Player;
        std::vector<std::pair<int, int>> oPositions = {
            {0, 0}, {2, 2}, {7, 7}
    };
    for (const auto& position : oPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = oPositions.size();
        return;
    }
    else if(Lvl == 4 || Lvl == 5  || Lvl == 6) //ROOK TUTORIAL ALSO WORKS FOR BISHOP LOL
    {


        int playerRow = 4;
        int playerCol = 4;
        grid[playerRow][playerCol].type = Piece::Type::Player;
    
        // Set Opponent pieces at specific positions
        std::vector<std::pair<int, int>> opponentPositions = {
            {0, 0}, {7, 7}, {0, 7}, {7,0} // Add more positions as needed
        };
    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        return;
    }
   else if(Lvl == 7)//CopyCat Level
   {
int playerRow = 4;
        int playerCol = 4;
        grid[playerRow][playerCol].type = Piece::Type::Player;
        int CopyCatRow = 3;
        int CopyCatCol = 3;
        grid[CopyCatRow][CopyCatCol].type = Piece::Type::CopyCat;
        // Set Opponent pieces at specific positions
       std::vector<std::pair<int, int>> opponentPositions = {
            {0, 0}, {7, 7}, {0, 7}, {7,0}, {1, 2}, {2, 2}, {4, 1} // Add more positions as needed
        };
    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        return;
   }
   
   else if(Lvl == 8)//Another CopyCat level
   {
        int playerRow = 6;
        int playerCol = 5;
        grid[playerRow][playerCol].type = Piece::Type::Player;
        grid[playerCol][playerRow].type = Piece::Type::CopyCat;
        // Set Opponent pieces at specific positions
       std::vector<std::pair<int, int>> opponentPositions = {
            {7, 0}, {7, 1}, {7, 2}, {7,3}, {0, 4}, {0, 5}, {0, 6}, {0,7},
            {6, 0}, {6, 1}, {6, 2}, {6,3}, {1, 4}, {1, 5}, {1, 6}, {1,7},// Add more positions as needed
        };

    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        return;
   }
   else if(Lvl == 9)//Guard Level
   {

        int playerRow = 6;
        int playerCol = 5;
        grid[playerRow][playerCol].type = Piece::Type::Player;
               std::vector<std::pair<int, int>> opponentPositions = {
            {0, 0},  {0, 2},  {0, 4},  {0, 6}, {0,7},
            // Add more positions as needed
        }; 
        std::vector<std::pair<int, int>> guardPositions = {
             {1, 0},  {2, 2},  {3, 4},  {4, 6}, {5,7}
        };
        for(const auto& position : opponentPositions) {
            int oRow = position.first;
            int oCol = position.second;
            grid[oRow][oCol].type = Piece::Type::Opponent;
            
        };
        for(const auto& position : guardPositions) {
            int oRow = position.first;
            int oCol = position.second;
            grid[oRow][oCol].type = Piece::Type::Guard;
        };
        opponents = guardPositions.size() + opponentPositions.size();
        Guards = guardPositions.size();
        return;
       
   }
   else if(Lvl == 10)//Duck Level
   {
  int PlayerRow = 5;
       int PlayerCol = 5;
       grid[PlayerRow][PlayerCol].type = Piece::Type::Player;
            
       
        std::vector<std::pair<int, int >> duckPositions = {
            {3,3}
        };
        std::vector<std::pair<int, int>> opponentPositions = {
            {1,1}, {1, 4}, {1, 5},
            {2,2}, {2,3},{2,4},{2,5},{2,6}, {2, 7}
            
        };
         for (const auto& position : duckPositions){
            int duckRow = position.first;
            int duckCol = position.second;
            grid[duckRow][duckCol].type = Piece::Type::Duck;
        }
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size();
        Ducks = duckPositions.size();
        return;
   }
   else if(Lvl == 11)//Wanderer
   {
  int PlayerRow = 3;
       int PlayerCol = 4;
       grid[PlayerRow][PlayerCol].type = Piece::Type::Player;
        
       
        std::vector<std::pair<int, int >> w_Positions = {
            {3,0}
        };
        std::vector<std::pair<int, int>> opponentPositions = {
            {1,1}, {1, 4}, {1, 5},
            {2,2}, {2,3},{2,4},{2,5},{2,6}, {2, 7}
            
        };
         for (const auto& position : w_Positions){
            int wRow = position.first;
            int wCol = position.second;
            
            grid[wRow][wCol].type = Piece::Type::Wanderer;
            grid[wRow][wCol].increasing = true;
        }
        grid[5][5].type = Piece::Type::WandererDest;
        grid[5][5].increasing = false;
        WandererDest_Row = 5;
        WandererDest_Col = 5;
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }
        opponents = opponentPositions.size() + w_Positions.size();
        Wanderers = w_Positions.size();
        return;
       
   }
   else if(Lvl == 12)// One of Everything, with a side of Opponents.
   {

       int PlayerRow = 2;   int PlayerCol = 2;
        grid[PlayerRow][PlayerCol].type = Piece::Type::Player;

        
        int wand_Row = 5; 
        int wand_Col = 6;
        grid[wand_Row][wand_Col].type == Piece::Type::Wanderer;
        grid[wand_Row][wand_Col].increasing = false;
        Wanderers += 1;
        
        WandererDest_Row = 3;
        WandererDest_Col = 3;
         grid[WandererDest_Row][WandererDest_Row].type == Piece::Type::WandererDest;
        std::vector<std::pair<int, int>> opponentPos = {
            {0, 0},  {0, 2},  {0, 4},  {0, 6}, {0,7}
        };
        std::vector<std::pair<int, int>> guardPos = {
            {1, 0},  {2, 3},  {3, 4},  {4, 6}, {5,7}
        };
        int CopyCat_Row = 5;
        int CopyCat_Col = 5;
        grid[CopyCat_Row][CopyCat_Col].type = Piece::Type::CopyCat;
        CopyCats++;
        
        for(const auto& position : guardPos) {
            int oRow = position.first;
            int oCol = position.second;
            grid[oRow][oCol].type = Piece::Type::Guard;
            
        }
        for(const auto& position : opponentPos) {
                        int oRow = position.first;
            int oCol = position.second;
            grid[oRow][oCol].type = Piece::Type::Opponent;
        }
        
        
        
        //int adjustments
        Guards = guardPos.size();
        opponents = Guards + opponentPos.size() + Wanderers;
        
        
        
        
    return;
   }
   else if(Lvl == 99){
int PlayerRow = 2;
int PlayerCol = 2;
grid[PlayerRow][PlayerCol].type = Piece::Type::Player;

std::vector<std::pair<int, int>> piecePositions = {
    {3, 0},     // Wanderer
    {4, 3},     // Opponent
    {5, 5},     // WandererDest
    {6, 1},     // CopyCat
    {6, 6},     // Guard
    {7, 2},     // Duck
};

for (size_t i = 0; i < piecePositions.size(); ++i) {
    int row = piecePositions[i].first;
    int col = piecePositions[i].second;

    if (grid[row][col].type == Piece::Type::Empty) {
        Piece::Type newType;

        switch (i) {
            case 0: newType = Piece::Type::Wanderer; break;
            case 1: newType = Piece::Type::Opponent; break;
            case 2: newType = Piece::Type::WandererDest; break;
            case 3: newType = Piece::Type::CopyCat; break;
            case 4: newType = Piece::Type::Guard; break;
            case 5: newType = Piece::Type::Duck; break;
            default: newType = Piece::Type::Empty; break;
        }

        // Place the piece and assign the type
        grid[row][col].type = newType;

        // Set the 'increasing' value for Wanderer and WandererDest
        if (newType == Piece::Type::Wanderer) {
            grid[row][col].increasing = true;
        } else if (newType == Piece::Type::WandererDest) {
            WandererDest_Row = row;
            WandererDest_Col = col;
            grid[row][col].increasing = false;
        }
    }


    opponents = piecePositions.size() - 1;
    Guards = 1;
    Wanderers = 1;
    Ducks = 1;
    CopyCats = 1;



   }
   /* else if(Lvl == 11){//Guards.
        std::vector<std::pair<int,int>> GuardPositions = {
            {0,0}, {7,1}, {0,2}, {7,3}, {0,4},{7,5}, {0,6},{7,7}
            };
    }*/}
    else {
    std::cout<< "\n No valid Level Input detected. Board initialized to 0.";
        int playerRow = 4;
        int playerCol = 4;
        grid[playerRow][playerCol].type = Piece::Type::Player;
    
        // Set Opponent pieces at specific positions
        std::vector<std::pair<int, int>> opponentPositions = {
            {1, 2}, {3, 3}, {4, 1} // Add more positions as needed
        };
       
    
        for (const auto& position : opponentPositions) {
            int opponentRow = position.first;
            int opponentCol = position.second;
            grid[opponentRow][opponentCol].type = Piece::Type::Opponent;
        }

        opponents = opponentPositions.size();
        return;
    }
    
};

void Board::reset() {
    for (int row = 0; row < ROWS; ++row) 
        for (int col = 0; col < COLS; ++col) {
            if(grid[row][col].type != Piece::Type::Empty){
                grid[row][col].type = Piece::Type::Empty;
            }
        }
    int opponents = 0;
    int Guards = 0;
    int Ducks = 0;
    int Wanderers = 0;
    int CopyCats = 0;
    int WandererDest_Row = -1;
    int WandererDest_Col = -1;
}
bool Board::LevelFailed(){
    int PlayerPieces = 0;
    for (int row = 0; row < ROWS; ++row) 
        for (int col = 0; col < COLS; ++col) {
            if(grid[row][col].type == Piece::Type::Player){
                PlayerPieces = PlayerPieces+1;
            }
        }
    if(PlayerPieces == 0 || PawnLevelFailed == true){
        return true;
    }
    else
    return false;
}
bool Board::LevelClear(){
    if(opponents > 0){
        return false;
    }
    else return true;
};
std::string Board::LTS_3by3(int row, bool isTop){
    std::string ReturnVal;
    std::string start = " ";
   std::string end = "        ";
    std::string num = std::to_string(row);
    std::string slot[10];
    std::string Empty = "|     |";
    std::string Player = "|     |";
    std::string Opponent = "|     |";
    std::string CopyCat = "|     |";
    std::string Guard_L = "|     |";
    std::string Guard_R = "|     |";
    std::string Guard = "|     |";
    std::string Wanderer = "|  |  |";
    std::string Duck_Top = "|     |";
    std::string Duck_Bot = "|^^^^^|";
    std::string WandererDest = "|  |  |";
    
    for(int col = 0; col <= COLS; ++col){
        if(grid[row][col].type == Piece::Type::Empty){
            slot[col] = Empty;
        }
        else if(grid[row][col].type == Piece::Type::Opponent){
            slot[col] = Opponent;
        }
        else if(grid[row][col].type == Piece::Type::CopyCat){
            slot[col] = CopyCat;
        }
        else if(grid[row][col].type == Piece::Type::Player){
            slot[col] = Player;
        }
        else if(grid[row][col].type == Piece::Type::Guard){
            slot[col] = Guard;
        }
        else if(grid[row][col].type == Piece::Type::Wanderer){
            slot[col] = Wanderer;
        }
        else if(grid[row][col].type == Piece::Type::Duck){
            if(isTop == true){
                slot[col] = Duck_Top;
            }
            else
            {
                slot[col] = Duck_Bot;
            }
            
        }
        else if(grid[row][col].type == Piece::Type::WandererDest){
            slot[col] = WandererDest;
        }
        else {
            slot[col] = "|?????|"; // Handle unknown type
        }
    }
  
    ReturnVal = start + slot[0] + slot[1] + slot[2] + slot[3] + slot[4] + slot[5] + slot[6] + slot[7] + end ;
    return ReturnVal;
};

std::string Board::LineToString(int row){
    std::string ReturnVal;
    std::string end = "       ";
    std::string start = " ";
   
    std::string num = std::to_string(row);
    std::string slot[10];
    std::string Empty = "|     |";
    std::string Player = "|  ⟁  |";
    std::string Opponent = "|  ♙  |";
    std::string CopyCat = "|O___O|";
    std::string Guard_L = "|<-o  |";
    std::string Guard_R = "|  o->|";
    std::string Guard = "|GUARD|";
    std::string Wanderer = "|-[o]-|";
    std::string Duck = "| ~o~ |";
    std::string WandererDest = "|-[ ]-|";
    
    for(int col = 0; col <= COLS; ++col){
        if(grid[row][col].type == Piece::Type::Empty){
            slot[col] = Empty;
        }
        else if(grid[row][col].type == Piece::Type::Opponent){
            slot[col] = Opponent;
        }
        else if(grid[row][col].type == Piece::Type::CopyCat){
            slot[col] = CopyCat;
        }
        else if(grid[row][col].type == Piece::Type::Player){
            slot[col] = Player;
        }
        else if(grid[row][col].type == Piece::Type::Guard){
            if (grid[row][col].increasing == true){
                slot[col] = Guard_R;
            }
            else slot[col] = Guard_L;
        }
        else if(grid[row][col].type == Piece::Type::Wanderer){
            slot[col] = Wanderer;
        }
        else if(grid[row][col].type == Piece::Type::Duck){
            slot[col] = Duck;
        }
        else if(grid[row][col].type == Piece::Type::WandererDest){
            slot[col] = WandererDest;
        }
        else {
            slot[col] = "|?????|"; // Handle unknown type
        }
    }
  
    ReturnVal = start + slot[0] + slot[1] + slot[2] + slot[3] + slot[4] + slot[5] + slot[6] + slot[7] + num + end ;
    return ReturnVal;
};


std::vector<std::string> Board::BrdOutput() {
    std::vector<std::string> BoardGui;
    std::string row0_U = LTS_3by3(0,1);
    std::string row0 = LineToString(0);
    std::string row0_D = LTS_3by3(0,0);
    
    std::string row1_U = LTS_3by3(1,1);
    std::string row1 = LineToString(1);
    std::string row1_D = LTS_3by3(1,0);
    
    std::string row2_U = LTS_3by3(2,1);
    std::string row2 = LineToString(2);
    std::string row2_D = LTS_3by3(2,0);
    
    std::string row3_U = LTS_3by3(3,1);
    std::string row3   = LineToString(3);
    std::string row3_D = LTS_3by3(3,0);
    
    std::string row4_U = LTS_3by3(4,1);
    std::string row4   = LineToString(4);
    std::string row4_D = LTS_3by3(4,0);
    
    std::string row5_U = LTS_3by3(5,1);
    std::string row5   = LineToString(5);
    std::string row5_D = LTS_3by3(5,0);
    
    std::string row6_U = LTS_3by3(6,1);
    std::string row6   = LineToString(6);
    std::string row6_D = LTS_3by3(6,0);
    
    std::string row7_U = LTS_3by3(7,1);
    std::string row7 = LineToString(7);
    std::string row7_D = LTS_3by3(7,0);

    //             
    BoardGui.push_back("||  A  ||  B  ||  C  ||  D  ||  E  ||  F  ||  G  ||  H  |<<Column  ");//
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##  vROWv ");//2
      BoardGui.push_back(row0_U);//0
      BoardGui.push_back(row0);
      BoardGui.push_back(row0_D);//0
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row1_U);//1
      BoardGui.push_back(row1);
      BoardGui.push_back(row1_D);//1
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row2_U);//2
      BoardGui.push_back(row2);
      BoardGui.push_back(row2_D);//2
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row3_U);//3
      BoardGui.push_back(row3);
      BoardGui.push_back(row3_D);
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row4_U);//4
      BoardGui.push_back(row4);
      BoardGui.push_back(row4_D);
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row5_U);//5
      BoardGui.push_back(row5);
      BoardGui.push_back(row5_D);
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row6_U);//7
      BoardGui.push_back(row6);
      BoardGui.push_back(row6_D);
      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back(row7_U);//7
      BoardGui.push_back(row7);
      BoardGui.push_back(row7_D);

      BoardGui.push_back("##=====##=====##=====##=====##=====##=====##=====##=====##       ");
      BoardGui.push_back("____________________________________________________________________" );//concat all the results into one big one.
       return BoardGui; 
        
        
        

}

void Board::display()  {//Outputs the board then checks if the Puzzle has been completed. Then loads the next level if available. 
       /* std::cout<<"\n||  0  ||  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  |<<Column\n" // << L 
                <<"##=====##=====##=====##=====##=====##=====##=====##=====##  vROWv\n|";*/
                std::vector<std::string> BoardGUI = BrdOutput();
    for(int i = 0; i < BoardGUI.size(); i++){
        std::cout << BoardGUI[i] << std::endl;
    }
    return;
};


std::pair<int, int> generateRandomPair() {
    // Set up random number generator with C++11's <random> library
    std::mt19937 rng(std::time(nullptr)); // Initialize seed based on current time
    std::uniform_int_distribution<int> dist(0, 7); // Range 0 to 7 inclusive
    
    int firstRandom = dist(rng);
    int secondRandom = dist(rng);

    return std::make_pair(firstRandom, secondRandom);
};
bool Board::isDuck(int pRow, int pCol){
    if(grid[pRow][pCol].type == Piece::Type::Duck){
        return true;
    }
    return false;
}
void Board::setWandererDestination() {
    if (WandererDest_Row == -1  || WandererDest_Col == -1) {
        
        return;
    }
    if (Wanderers == 0){
          for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col){
                if(grid[row][col].type == Piece::Type::WandererDest){//currently you can only have one Wanderer in a level at a tine.
                    grid[row][col].type == Piece::Type::Empty;
                    WandererDest_Row = -1;
                    WandererDest_Col = -1;
                    break;
                }
            }
            }
            return;
    }
    std::cout << "Wanderers Deciding where they should go..." << std::endl;
    std::pair<int, int> WandererDest;
    // if you wanted to put multiple wanderers in a level, make a vector of paired ints
            
    // Check if a WandererDest piece was found on the board. This is a redundant check, but i like my safeguards.

        do{
        WandererDest = generateRandomPair();
        }
        while(grid[WandererDest.first][WandererDest.second].type != Piece::Type::Empty);
            //set the current WandererDest to Empty.
            grid[WandererDest.first][WandererDest.second].type = Piece::Type::WandererDest;
            WandererDest_Row = WandererDest.first;
            WandererDest_Col = WandererDest.second;
            
            return;
            
}
void Board::moveWanderers() {//moves teh wanderer to 

    std::cout << "wanderers moving" << std::endl; 
    std::string PlayerCap = "The Knight Errant has been eliminated by a Wanderer.";
    std::string CopyCap =   "The CopyCat has been eliminated by a Wanderer.";
    int iRow = -1;
    int iCol = -1;
            for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col){
                if(grid[row][col].type == Piece::Type::Wanderer){//currently you can only have one Wanderer in a level at a tine.
                    iRow = row;
                    iCol = col;
                    break;
                }
            }
        }
    // Check if a Wanderer piece was found on the board. This is a redundant check, but i like my safeguards.
    if (iRow == -1 || iCol == -1) {
        return;
    }
    if(grid[WandererDest_Row][WandererDest_Col].type == Piece::Type::Player){
        CrawlPrint(PlayerCap);
    }
    if(grid[WandererDest_Row][WandererDest_Col].type == Piece::Type::CopyCat){
        CrawlPrint(CopyCap);
        CopyCats--;
    }
    //Move Wanderer to the previous coordinates set for the Destination. Destination can be "Eliminated" by a player.
    grid[iRow][iCol].type = Piece::Type::Empty;   
    grid[WandererDest_Row][WandererDest_Col].type = Piece::Type::Wanderer;
    
    
    setWandererDestination();        
    return;
}
void Board::moveDuck() {//randomly moves the duck to a place on the map. cannot be player.
    std::cout << "Ducks Migrating...\n";
    std::pair<int, int> Duck;
    int iRow = -1;
    int iCol = -1;
            for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col){
                if(grid[row][col].type == Piece::Type::Duck){//currently you can only have one Wanderer in a level at a tine.
                    iRow = row;
                    iCol = col;

                    break;
                }
            }
            }
        if (iRow == -1 || iCol == -1) {
            std::cout << "ERROR: no Duck Found.";
            return;
        }
        do
        {
            Duck = generateRandomPair();
        }while(grid[Duck.first][Duck.second].type != Piece::Type::Empty);
        
        grid[iRow][iCol].type = Piece::Type::Empty;
        grid[Duck.first][Duck.second].type = Piece::Type::Duck;
        std::cout << "Duck has moved to " << Duck.first << " " << Duck.second << std::endl; 
     return;
}
void Board::moveGuards() {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (grid[row][col].type == Piece::Type::Guard) {
                // Determine the target column based on the increasing flag
                int targetCol = (grid[row][col].increasing) ? col + 1 : col - 1;

                // Check if the target column is within boundaries
                if (targetCol < 0 || targetCol >= COLS) {
                    // Switch the increasing flag if the next move would be out of bounds
                    grid[row][col].increasing = !grid[row][col].increasing;
                    targetCol = (grid[row][col].increasing) ? col + 1 : col - 1;
                }

                // Check if the target cell is within boundaries
                if (targetCol >= 0 && targetCol < COLS) {
                    // Check if the target cell is empty, contains a Player piece, or is a CopyCat
                    if (grid[row][targetCol].type == Piece::Type::Empty ||
                        grid[row][targetCol].type == Piece::Type::Player ||
                        grid[row][targetCol].type == Piece::Type::CopyCat) {
                        // Move the Guard to the target cell
                        grid[row][targetCol] = grid[row][col];
                        grid[row][col].type = Piece::Type::Empty;
                    } else {
                        // Switch the increasing flag and move as if it had the new flag value
                        grid[row][col].increasing = !grid[row][col].increasing;
                        int newTargetCol = (grid[row][col].increasing) ? col + 1 : col - 1;
                        // Check if the new target column is within boundaries
                        if (newTargetCol >= 0 && newTargetCol < COLS) {
                            // Check if the new target cell is empty, contains a Player piece, or is a CopyCat
                            if (grid[row][newTargetCol].type == Piece::Type::Empty ||
                                grid[row][newTargetCol].type == Piece::Type::Player ||
                                grid[row][newTargetCol].type == Piece::Type::CopyCat) {
                                // Move the Guard to the new target cell
                                grid[row][newTargetCol] = grid[row][col];
                                grid[row][col].type = Piece::Type::Empty;
                            }
                        }
                    }
                }
            }
        }
    }
}

std::pair<int, int> Board::GetMirroredPosition(int playerRow, int playerCol) {
    int mirroredRow = ROWS - 1 - playerRow;
    int mirroredCol = COLS - 1 - playerCol;
    return std::make_pair(mirroredRow, mirroredCol);
}


void Board::moveCopyCats(int pRow, int pCol){
    std::string debug = "THIS IS A DEBUG MESSAGE";
    CrawlPrint(debug);
     // Find the position of the player piece on the board
     if(CopyCats == 0){
         return;
     }
     int initialRow = -1;
     int initialCol = -1;
     std::pair<int, int> CopiedMoves = GetMirroredPosition(pRow, pCol);
     
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {   
            if (grid[row][col].type == Piece::Type::CopyCat) {
                initialRow = row;
                initialCol = col;
                break;
            }
        }
    }

    // Check if a CopyCat piece was found on the board
    if (initialRow == -1 || initialCol == -1) {
        return;
    }

    // Check if the destination position is valid; if not, do nothing
    if (CopiedMoves.first < 0 || CopiedMoves.first >= ROWS || CopiedMoves.second < 0 || CopiedMoves.second >= COLS) {
        return;
    }
    
    // Handle opponent removal
    if (grid[CopiedMoves.first][CopiedMoves.second].type == Piece::Type::Opponent) {
        opponents--;
        if (grid[CopiedMoves.first][CopiedMoves.second].type == Piece::Type::Wanderer){
            Wanderers--;
            
        }
        //decrease number of Piece types if a piece of that type is taken TODO!!!!!
    }
    
    if (grid[CopiedMoves.first][CopiedMoves.second].type == Piece::Type::Player) {
       grid[CopiedMoves.first][CopiedMoves.second].type = Piece::Type::Empty;
       std::cout << "\n             The Knight Errant has been Felled by the CopyCat. The Kingdom has truly been defeated.";
       
    }
    // Check if the destination piece is a Duck
    if (grid[CopiedMoves.first][CopiedMoves.second].type == Piece::Type::Duck) {
        std::string QUACKED = "\n             CopyCat has been QUACKED. They return to their last spot.";
        CrawlPrint(QUACKED);
        return;
    }
    
    // Delete the piece at the destination position if it is not empty
    if (grid[CopiedMoves.first][CopiedMoves.second].type != Piece::Type::Empty ) {
        std::cout << "\n             CopyCat Eliminated a :" << grid[CopiedMoves.first][CopiedMoves.second].getTypeName() << std::endl;
        grid[CopiedMoves.first][CopiedMoves.second].type = Piece::Type::Empty;
    }

    // Move the CopyCat piece to the destination position
    grid[initialRow][initialCol].type = Piece::Type::Empty;
    grid[CopiedMoves.first][CopiedMoves.second].type = Piece::Type::CopyCat;
}



void Board::movePlayerPiece(int destRow, int destCol) {
    int initialRow = -1;
    int initialCol = -1;
    std::string GuardKilled = "The Knight-Errant has slain a Guard";
    std::string WandererKilled = "The Knight-Errant has slain a Wanderer";
    std::string Quackd = "the Knight-Errant has been QUACKED";
    std::string CopyKilled = "The Knight-Errant has Slain the CopyCat";
    // Find the position of the player piece on the board
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {   
            if (grid[row][col].type == Piece::Type::Player) {
                initialRow = row;
                initialCol = col;
                break;
            }
        }
    }

    // Check if a player piece was found on the board
    if (initialRow == -1 || initialCol == -1) {
        std::cout << "No player piece found on the board." << std::endl;
        return;
    }

    // Check if the destination position is valid
    if (destRow < 0 || destRow >= ROWS || destCol < 0 || destCol >= COLS) {
        std::cout << "Invalid destination position." << std::endl;
        return;
    }
    
    // Handle opponent removal
    if (grid[destRow][destCol].type != Piece::Type::Empty 
        && grid[destRow][destCol].type != Piece::Type::Duck 
        && grid[destRow][destCol].type != Piece::Type::CopyCat) {
        opponents--;
    }

    
    // Check if the destination piece is a Duck
    if(grid[destRow][destCol].type == Piece::Type::Duck) {
        std::cout << "the Knight-Errant has been QUACKED" << std::endl;
        return;
    }
    //CopyCat Death Very Sad
    if(grid[destRow][destCol].type == Piece::Type::CopyCat) {
        CrawlPrint(CopyKilled);
        CopyCats--;
        
    }
    
    if(grid[destRow][destCol].type == Piece::Type::Wanderer){
        CrawlPrint(WandererKilled);
        Wanderers--;
    }
    
    if(grid[destRow][destCol].type == Piece::Type::Guard){
        CrawlPrint(GuardKilled);
        Guards--;
    }
    // Delete the piece at the destination position if it is not empty
    if (grid[destRow][destCol].type != Piece::Type::Empty) {
        std::cout << "the Knight-Errant has Eliminated a :" << grid[destRow][destCol].getTypeName() << std::endl;
        grid[destRow][destCol].type = Piece::Type::Empty;
    }

    // Move the player piece to the destination position
    grid[initialRow][initialCol].type = Piece::Type::Empty;
    grid[destRow][destCol].type = Piece::Type::Player;
    moveCopyCats(destRow,destCol);
}

    
std::vector<std::pair<int, int>>Board::getValidMoves(Card* myCard) //THIS IS OUR BIG PALOOKA HERE>
//BIG BOY HAS TO COMPARE THE CARD TYPE AND RETURN A LIST OF VALID MANEUVERS WITHIN THE BOUNDARIES OF THE BOARD.
//TODO: Bishop and Queen.

{
    int iRow = -1;
    int iCol = -1;
    //function finds the player piece. Need to change this to a Player array?
    //or maybe have a new piece type?
    
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                if(grid[i][j].type == Piece::Type::Player){
                    iRow = i;
                    iCol = j;
                }
            }
        
    }
    int dRow;
    int dCol;

    std::vector<std::pair<int,int>> ValidMoves;
    //1. Find Player Piece x and y coords.;  
    //2. find all possible destinations using a switch statement. Each case will contain a for loop looking for all the possible destinations on a board.
    switch(myCard->type_){
        case Card::CardType::Pawn:
                {
                //make sure that move is within bounds.
                if((iRow-1)>=0 ){
                 if(grid[iRow-1][iCol].type == Piece::Type::Empty){    
                dRow = iRow-1;
                dCol = iCol;
                std::pair<int, int> Pair1;
                Pair1.first = dRow;
                Pair1.second = dCol;
                ValidMoves.push_back(Pair1);
                 }
                
                if  (grid[iRow-1][iCol-1].type == Piece::Type::Opponent)
                {
                    dRow = iRow - 1;
                    dCol = iCol - 1;
                    std::pair<int, int> newPair;
                    newPair.first = dRow;
                    newPair.second = dCol;
                    ValidMoves.push_back(newPair);
                }
                    
                if (grid[iRow-1][iCol+1].type == Piece::Type::Opponent){
                    dRow = iRow-1;
                    dCol = iCol+1;
                   std::pair<int, int> newPair;
                    newPair.first = dRow;
                    newPair.second = dCol;
                    ValidMoves.push_back(newPair);
                }
                    return ValidMoves;
                }
                return ValidMoves;
                }
        case  Card::CardType::Knight:
        //2 up 1 left/right.
        //2left/right one up/down\
        //currently Bugged
        //TODO: debug the 0,0 glitch. 
            {
                // iRow +2 iCol +1
               std::vector<std::pair<int, int>> Moves = {
                { iRow + 2, iCol + 1 },   { iRow + 2, iCol - 1 }, { iRow + 1, iCol + 2 }, { iRow + 1, iCol - 2 },
                { iRow - 2, iCol - 1 }, { iRow - 2, iCol + 1 }, { iRow - 1, iCol + 2 }, { iRow - 1, iCol - 2 } 
                };

                for(int i = 0; i < Moves.size(); i++){
                    if(IsInBounds(Moves[i]) == true) 
                    {
                        ValidMoves.push_back(Moves[i]);
                    }
                    
                }
            }
                return ValidMoves;
        case Card::CardType::Queen://There is currently a glitch with the outputs. apparently there is duplicate pairs being sent back.
        //do Bishop and Rook.
        //BISHOP
        for (int dRow = -1; dRow <= 1; dRow += 2) {
                    for (int dCol = -1; dCol <= 1; dCol += 2) {
                        int row = iRow + dRow;
                        int col = iCol + dCol;
                        while (IsInBounds({row, col})) {
                            if (grid[row][col].type == Piece::Type::Empty) {
                                ValidMoves.push_back({row, col});
                            } else {
                                ValidMoves.push_back({row, col});
                                break; // Stop adding moves if there's a piece in the way
                            }
                            row += dRow;
                            col += dCol;
                        }
                    }
                }
               
                    //ROOK MOVES
          for (int dRow = -1; dRow <= 1; dRow += 2) {
                int row = iRow + dRow;
                int col = iCol;
                while (IsInBounds({row, col})) {
                    if (grid[row][col].type == Piece::Type::Empty) {
                        ValidMoves.push_back({row, col});
                    } else {
                        ValidMoves.push_back({row,col});
                        break; // Stop adding moves in this direction if there's a piece in the way
                    }
                    row += dRow;
                }
            }
            for (int dCol = -1; dCol <= 1; dCol += 2) {
                int row = iRow;
                int col = iCol + dCol;
                while (IsInBounds({row, col})) {
                    if (grid[row][col].type == Piece::Type::Empty) {
                        ValidMoves.push_back({row, col});
                    } else {
                        ValidMoves.push_back({row,col});
                        break; // Stop adding moves in this direction if there's a piece in the way
                    }
                    col += dCol;
                }
            }
            return ValidMoves;
        case Card::CardType::King:
        //one in all directions. returns an array of size 8
        //(0, 1, 2)
        //(3,    4) 
        //(5, 6, 7)
        {
            //iRow +1, iRow,  iRow -1, iCol+1, iCol, iCol-1
            for(int r = iRow-1; r <= iRow+1; r++  ){
                for(int c = iCol -1; c <= iCol +1; c++){
                    std::pair<int, int> Pear;
                    Pear.first = r;
                    Pear.second = c;
                    if(IsInBounds(Pear) == true && grid[r][c].type != Piece::Type::Player){
                        ValidMoves.push_back(Pear);
                    }
                }
            }
            //only if within bounds.
        }
            return ValidMoves;
        case Card::CardType::Bishop:
        //find all diagonals from current position. Do not continue if there is a piece in the way.
                  for (int dRow = -1; dRow <= 1; dRow += 2) {
                    for (int dCol = -1; dCol <= 1; dCol += 2) {
                        int row = iRow + dRow;
                        int col = iCol + dCol;
                        while (IsInBounds({row, col})) {
                            if (grid[row][col].type == Piece::Type::Empty) {
                                ValidMoves.push_back({row, col});
                            } else {
                                ValidMoves.push_back({row, col});
                                break; // Stop adding moves if there's a piece in the way
                            }
                            row += dRow;
                            col += dCol;
                        }
                    }
                }
                return ValidMoves;
        case Card::CardType::Rook://
        //find all Up Down left and right. Do not continue if there is a piece in the way.
        //4 do while statements seems kind of ugly is there a way i can make this more efficient?
        //Really inefficient way to do this. Problem: memory usage was being overloaded. took 40 seconds to load rook moves. 
        //solution: there was an error in my code that was incrementing along the x access when the x access had already been done. this resulted in a lot of unnecessary 
        //checks, creating the cursed forever load.
        {
          for (int dRow = -1; dRow <= 1; dRow += 2) {
                int row = iRow + dRow;
                int col = iCol;
                while (IsInBounds({row, col})) {
                    if (grid[row][col].type == Piece::Type::Empty) {
                        ValidMoves.push_back({row, col});
                    } else {
                        ValidMoves.push_back({row,col});
                        break; // Stop adding moves in this direction if there's a piece in the way
                    }
                    row += dRow;
                }
            }
            for (int dCol = -1; dCol <= 1; dCol += 2) {
                int row = iRow;
                int col = iCol + dCol;
                while (IsInBounds({row, col})) {
                    if (grid[row][col].type == Piece::Type::Empty) {
                        ValidMoves.push_back({row, col});
                    } else {
                        ValidMoves.push_back({row,col});
                        break; // Stop adding moves in this direction if there's a piece in the way
                    }
                    col += dCol;
                }
            }
        }
            return ValidMoves;
          
        case Card::CardType::Empty:
        
        
            return ValidMoves;

        default:
            return ValidMoves;
    }
};


bool Board::IsInBounds(std::pair<int, int> TempPair) {
    if((TempPair.first < 0) || (TempPair.first >7) )
    {
        return false;
    }
    if((TempPair.second <0) || (TempPair.second > 7))
    {
        return false;
    }
    return true;
    
}