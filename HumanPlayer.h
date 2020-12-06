//
// Created by natha on 12/7/2018.
//

#ifndef TRAP_HUMANPLAYER_H
#define TRAP_HUMANPLAYER_H

#include "Player.h"

class HumanPlayer: public Player {
public:
    explicit HumanPlayer(int);
    void playTurn() override;

private:

};


#endif //TRAP_HUMANPLAYER_H