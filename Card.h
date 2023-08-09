#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <array>


class Card
{
public:
bool isPlayed = false;
enum CardType {
	Empty, // used for Command Line
    Pawn = 2,
    King,
    Bishop,
    Knight,
    Rook,
    Queen
};
Card(CardType type) : type_(type) {
     Print();
};
std::vector<std::string> myCard;
Card() {
};
    virtual ~Card() {

        myCard.clear();
    };
    virtual CardType GetType() const {
        return type_;
    }
  
    virtual std::string getCard() const
    {
        switch (type_) {
        case CardType::Pawn:
            return "  Pawn  ";
        case CardType::Knight:
            return " Knight";
        case CardType::Queen:
            return " Queen ";
        case CardType::King:
            return "  King  ";
        case CardType::Bishop:
            return " Bishop";
        case CardType::Rook:
            return "Rook";
        case CardType::Empty:
            return "Empty";

        default:
            return "Unknown";

        }
      }
      void Print() {
             
    

        switch (type_) {
        case CardType::Pawn:       myCard = {"|        PAWN       |",
                                             "|___________________|",
                                             "|    ___________    |",
                                             "|    |_|_|_|_|_|    |",
                                             "|    |_|█|█|█|_|    |",
                                             "|    |_|_|I|_|_|    |",
                                             "|    |_|_|_|_|_|    |",
                                             "|    |_|_|_|_|_|    |",
                                             "|___________________|",
                                             "| Attack Diagonal 1 |",
                                             "| Can Move Up 1 if  |",
                                             "|    Not Blocked    |",
                                             "|___________________|"};
        break;
    
            
        case CardType::Knight:
                                myCard =  { "|       KNIGHT      |",
                                            "|___________________|",
                                            "|    ___________    |",
                                            "|    |_|█|_|█|_|    |",
                                            "|    |█|_|_|_|█|    |",
                                            "|    |_|_|I|_|_|    |",
                                            "|    |█|_|_|_|█|    |",
                                            "|    |_|█|_|█|_|    |",
                                            "|___________________|",
                                            "| Attack Spaces in  |",
                                            "|    An L Shape     |",
                                            "|                   |",
                                            "|___________________|"};
        
             break;
                
                
        case CardType::Queen:
        myCard =  {   "|       QUEEN       |",
        "|___________________|",
        "|    ___________    |",
        "|    |█|_|█|_|█|    |",
        "|    |_|█|█|█|_|    |",
        "|    |█|█|I|█|█|    |",
        "|    |_|█|█|█|_|    |",
        "|    |█|_|█|_|█|    |",
        "|___________________|",
        "| Attack long lines |",
        "|  in any Direction |",
        "|                   |",
        "|___________________|"};
            
            break;
             
         
        case CardType::King:
                myCard = {"|        KING       |",
                "|___________________|",
                "|    ___________    |",
                "|    |_|_|_|_|_|    |",
                "|    |_|█|█|█|_|    |",
                "|    |_|█|I|█|_|    |",
                "|    |_|█|█|█|_|    |",
                "|    |_|_|_|_|_|    |",
                "|___________________|",
                "|   Attack Or Move  |",
                "| One Space In Any  |",
                "|     Direction     |",
                "|___________________|"};
                
              break;
        

        case CardType::Bishop:
            myCard ={    "|       BISHOP      |",
            "|___________________|",
            "|    ___________    |",
            "|    |█|_|_|_|█|    |",
            "|    |_|█|_|█|_|    |",
            "|    |_|_|I|_|_|    |",
            "|    |_|█|_|█|_|    |",
            "|    |█|_|_|_|█|    |",
            "|___________________|",
            "|   Attack Or Move  |",
            "| In Long Diagonals |",
            "|                   |",
            "|___________________|"};
            
            
        
        break;
        case CardType::Rook: 
        myCard = { "|        ROOK       |",
            "|___________________|",
            "|    ___________    |",
            "|    |_|_|█|_|_|    |",
            "|    |_|_|█|_|_|    |",
            "|    |█|█|I|█|█|    |",
            "|    |_|_|█|_|_|    |",
            "|    |_|_|█|_|_|    |",
            "|___________________|",
            "|   Attack Or Move  |",
            "|   In Long Lines   |",
            "|                   |",
            "|___________________|",
            };
            break;
        
        case CardType::Empty:
        myCard = {"|       EMPTY       |",
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
            break;
        default:
                {myCard = 
                {
                    "| ERROR ERROR ERROR |",
                    "|___________________|",
                    "| ERROR ERROR ERROR |",
                    "| ERROR ERROR ERROR |",
                    "| ERROR ERROR ERROR |",
                    "| ERROR ERROR ERROR |",
                    "| ERROR ERROR ERROR |",
                    "| ERROR ERROR ERROR |",
                    "|___________________|",
                    "|If you see this the|",
                    "|CardType wasnt read|",
                    "|or ptr malfunction |",
                    "|___________________|"
                    };
                    break;}
                    
        }
        return;

        
    
};

    CardType type_;
   
};

