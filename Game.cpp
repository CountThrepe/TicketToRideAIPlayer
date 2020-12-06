//
// Created by natha on 12/7/2018.
//

#include "Game.h"
#include "Board.h"

using namespace std;

Game::Game() {
    numPlayers = getIntput("Enter the number of players (2-5): ", 2, 5);
    numAutoPlayers = getIntput("Enter the number of automated players: ", 0, numPlayers);

    players = new Player*[numPlayers];

    for(int i = 0; i < numPlayers; i++) {
        Player *p;
        if(i < numAutoPlayers) p = new AutoPlayer(i+1);
        else p = new HumanPlayer(i+1);
        players[i] = p;
    }
}

Game::~Game() {
    for(int i = 0; i < numPlayers; i++) delete players[i];
    delete[] players;
    Board::removeInstance();
}

void Game::play() {
    bool done = false;
    int lastTurn = 0;
    while(!done) {
        for(int i = 0; i < numPlayers; i++) {
            cout << "Continue? ";
            cin.ignore();
            cout << endl;

            Player *p = players[i];
            p->playTurn();
            if(lastTurn == p->getPlayerNumber()) {
                done = true;
                break;
            } else if(lastTurn == 0 && p->getNumTrains() < 3) {
                lastTurn = p->getPlayerNumber();
                cout << "Player " << p->getPlayerNumber() << " has only " << p->getNumTrains() << " train(s) left! Last Round!" << endl;
            }
        }
    }
}

void Game::printScores() {
    for(int i = 0; i < numPlayers; i++) {
        Player *p = players[i];
        cout << "Player " << p->getPlayerNumber() << " has " << p->getScore() << " points." << endl;
    }
}

int Game::getIntput(string prompt, int min, int max) {
    string temp;
    int intput;
    string jk = "Please enter a number between ";
    while(true) {
        cout << prompt;
        getline(cin, temp);
        string::const_iterator it = temp.begin();
        while (it != temp.end() && isdigit(*it)) it++;
        if(!temp.empty() && it == temp.end() && temp.length() < 6 && (intput = stoi(temp)) >= min && intput <= max)
            return intput;
        cout << jk << min << " and " << max << "." << endl << endl;
    }
}
