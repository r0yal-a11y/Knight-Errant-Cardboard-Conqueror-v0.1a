#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Card.h"
#include "Util.h"
struct Piece {
    enum class Type { 
        Empty,        // Empty space
        Player,       // Your player piece
        Opponent,     // Opponent's piece
        CopyCat,      // Copies the Player. Can take the VIP. Cannot take Player Piece
        Duck,         // Blocks Passage of all units. Cannot be destroyed.
        Wanderer,     // Place where Wanderer currently is. Moves as a Queen 
        WandererDest, // Place where Wanderer will move.
        Guard         // Moves side to side, unless a Duck is there.
    };

    bool increasing;
    bool isOTeam = true;

    // Constructors
    Piece() : type(Type::Empty), increasing(false) {}

    Piece(Type myType) : type(myType), increasing(false) {}

    Type type;

    // Function to get the string representation of the Type
    std::string getTypeName() const {
        switch (type) {
            case Type::Empty: return "Empty";
            case Type::Player: return "Player";
            case Type::Opponent: return "Opponent";
            case Type::CopyCat: return "CopyCat";
            case Type::Duck: return "Duck";
            case Type::Wanderer: return "Wanderer";
            case Type::Guard: return "Guard";
        }
        return "Unknown"; // Return "Unknown" for any unrecognized Type
    }
};

class Board {
public:
    static const int ROWS = 8;
    static const int COLS = 8;
    const int Turns = 0;
    const int Moves = 0;
    

    std::vector<std::vector<Piece>> grid;
    std::vector<std::string> BrdOutput();
    std::string LineToString(int row);
    std::string LTS_3by3(int row, bool isTop);

    Board();
    ~Board();
    void initialize();
    void init(int myLevel);
    void reset();
    void display() ;
    std::vector<std::pair<int, int>> getValidMoves(Card* myCard);
    
    void movePlayerPiece(int destRow, int destCol);
    void moveCopyCats(int destRow, int destCol);

  
    
    //moves for all pieces
        //Guard Logic
    void moveSidetoSide();
    void moveDuck();
    void moveGuards();
    void moveWanderers();
    void setWandererDestination();
    
    
    int WandererDest_Row = -1;
    int WandererDest_Col = -1;
    
    int opponents = 0;
    int Guards = 0;
    int Ducks;
    int Wanderers = 0;
    int CopyCats = 0;
    bool PlayerAlive();
    bool LevelClear();
    //RandomCoords handles both duck and wandererdest placement. if canTake is on, it will do the logic for Wandrer. if not, it is a duck, and sets the coords. 
    std::pair<int, int> GetRandomCoords();
    std::pair<int, int> GetMirroredPosition(int playerRow, int playerCol);
    bool LevelFailed();
    bool isDuck(int pRow, int pCol);
    bool IsInBounds(std::pair<int, int> TempPair);
    bool PawnLevelFailed = false;
};

#endif  // BOARD_H