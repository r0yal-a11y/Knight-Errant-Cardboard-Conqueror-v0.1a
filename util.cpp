#include "Util.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>

void CrawlPrint(const std::string& text) {
    int charactersPerMinute = 500 * 5; // Target speed: 230 words per minute
    int millisecondsPerChar = 60000 / charactersPerMinute;

    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsPerChar));
    }
    std::cout << std::endl;
}
void ReadCheck() {
    std::cout <<std::setw(100) << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ShowMenu() {
    std::cout << "this is the menu it is not finished" << std::endl;
    
    return;
}
void NewPage(){
        for(int i = 0; i <= 80; i++ ){
    std::cout << std::endl;
    }
}
void PrintHint(int LvL){

    switch (LvL) {
        case 0:
            std::cout << std::setw(60) << "The King was able to Move wherever he wanted.\n"
                      << std::setw(45) << "...   However, he was also a slow mover.\n"
                      << std::setw(52) << " Perhaps that is why he fell?\n";
            break;
        case 1:
            std::cout << std::setw(75) << "Pawns were simple folk.  They'd always attack the other lane, but would NEVER fight WHAT WAS IN FRONT of them.\n" 
                      << std::setw(75) << "Nonetheless, they were loyal, and would never step an inch back.\n";
            break;
        case 2:
            std::cout << std::setw(60) << "Knights were Tricksters, able to maneuver around the battlefield with cunning and speed.\n"
                      << std::setw(65) << "Their horses allowed them to move past ranks of soldiers, be they friend or foe.\n"
                      << std::setw(75) << "The best Knights could see the battle before it happened, and were always in the right place at the right time.\n";
            break;
        case 3:
            std::cout << std::setw(60) << "Bishops were interesting fellows. \n"
                      << std::setw(65) << "They always loved having their stairs.\n"
                      << std::setw(75) << "Maybe thats why they built their Temples DIAGONALLY?\n";
            break;
        case 4:
            std::cout << std::setw(60) << "The Rooks were strange folk.\n"
                      << std::setw(65) << "In many ways, they were very strict about their responsibilities.\n"
                      << std::setw(75) << "While they'd never move out of their lane, They'd always keep their LANE clean of crime....\n";
            break;
        case 5:
            std::cout << std::setw(65) << "In many ways, the Queen was made for battle. \n"
                      << std::setw(60) << "She would take charge of the wars, Aggressively maneuvering from one corner of the battlefield to the other.\n"
                      << std::setw(72) << "She should have been more Careful with her movements.\n";
            break;
        case 6:
            std::cout << std::setw(75) << "The Knight-Errant Begins their crusade. A simple Supply Raid would begin their Conquest.\n";
            break;
        case 7:
            std::cout << std::setw(75) << "Word Spread of the Knight-Errant, inspiring others to join the cause.\n"
                      << std::setw(85) << "The Knight-Errant would have to be careful, or these untrained CopyCats might get hurt.\n";
            break;
        case 8:
            std::cout << std::setw(75) << "The Knight-Errant became more comfortable with the idea of CopyCats.\n"
                      << std::setw(85) << "If the CopyCats' Behavior was predictable, the Knight-Errant could strategize new tactics.\n";
            break;
        case 9:
            std::cout << std::setw(75) << "The False King was catching on to the Knight-Errant.\n"
                      << std::setw(70) << "Guards were now on the lookout, patrolling the Rows in search of the Knight.\n";
            break;
        case 10:
            std::cout << std::setw(75) << "The Knight Errant knew that Duck migrations were never to be trifled with.\n"
                      << std::setw(60) << "While the Knight was capable of many things, defeating a Duck was not one of them.\n"
                      << std::setw(70) << "Whenever the Knight Errant encountered a Duck, they would always retreat, no matter the circumstance.\n";
            break;
        case 11:
            std::cout << std::setw(75) << "A bounty was placed on the Knight Errant's head.\n"
                      << std::setw(80) << "Wanderers came, looking to collect. Armed with advanced teleportation magics, these Wanderers were not to be trifled with.\n";
            break;
        case 12:
            std::cout << std::setw(75) << "The Knight Errant's Conquest was coming to Fruition;\n"
                      << std::setw(80) << "The False King pulled everything he could to stop the Knight Errant's Crusade of Vengeance.\n"
                      << std::setw(75);
            break;
        default:
            std::cout << std::setw(75) << "You should not be seeing this message. It is an Error Message.\n";
            break;
    }

}
