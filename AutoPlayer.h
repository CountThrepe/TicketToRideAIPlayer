//
// Created by natha on 12/7/2018.
//

#ifndef TRAP_AUTOPLAYER_H
#define TRAP_AUTOPLAYER_H

#include "Player.h"

class AutoPlayer: public Player {
public:
    explicit AutoPlayer(int);
    ~AutoPlayer() override;
    void playTurn() override;

private:
    Route *findWorkingRoute(Destination*);
    int getEdgeWeight(Route*, int*);
    int getEdgeWeight(City*, City*, int*);
    int getMaxColorIndex(int*);
    int getBestColorIndex(int*, int);

    void printHand();

    int *hand;
    Destination *dest;

    struct PQ;
};


#endif //TRAP_AUTOPLAYER_H
