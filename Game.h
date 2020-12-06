//
// Created by natha on 12/7/2018.
//

#ifndef TRAP_GAME_H
#define TRAP_GAME_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "HumanPlayer.h"
#include "AutoPlayer.h"

class Game {
public:
    Game();
    ~Game();
    void play();
    void printScores();
    int getIntput(std::string, int, int);

private:
    Player **players;
    int numPlayers;
    int numAutoPlayers;
};


#endif //TRAP_GAME_H
