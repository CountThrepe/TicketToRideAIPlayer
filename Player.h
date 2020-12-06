//
// Created by natha on 12/7/2018.
//

#ifndef TRAP_PLAYER_H
#define TRAP_PLAYER_H

#include <iostream>
#include "Board.h"

class Player {
public:
    explicit Player(int);
    virtual ~Player();
    int getPlayerNumber();
    void increaseScore(int);
    int getScore();
    void playTrains(int);
    int getNumTrains();
    virtual void playTurn() = 0;

private:
    int playerNum;
    int score;
    int numTrains;

protected:
    int getIntput(std::string, int, int);
    Board *b;
};


#endif //TRAP_PLAYER_H
