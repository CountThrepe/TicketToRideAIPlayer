//
// Created by natha on 12/7/2018.
//

#include "Player.h"

using namespace std;

Player::Player(int num) {
    playerNum = num;
    numTrains = 45;
    score = 0;
    b = Board::getInstance();
}

Player::~Player() = default;

int Player::getPlayerNumber() {
    return playerNum;
}

void Player::increaseScore(int points) {
    score += points;
}

int Player::getScore() {
    return score;
}

void Player::playTrains(int trains) {
    if(trains < 1 || trains > 6) cout << "Error! Player " << getPlayerNumber() << " tried to play " << trains << "trains!" << endl;
    else if(trains > numTrains) cout << "Error! Player " << getPlayerNumber() << " tried to play down more trains than they had!" << endl;
    else {
        int points = trains;
        if(trains == 3) points = 4;
        else if(trains == 4) points = 7;
        else if(trains == 5) points = 10;
        else if(trains == 6) points = 15;
        increaseScore(points);

        numTrains -= trains;
    }
}

int Player::getNumTrains() {
    return numTrains;
}

int Player::getIntput(string prompt, int min, int max) {
    string temp;
    int intput;
    while(true) {
        cout << prompt;
        getline(cin, temp);
        string::const_iterator it = temp.begin();
        while (it != temp.end() && isdigit(*it)) it++;
        if(!temp.empty() && it == temp.end() && temp.length() < 6 && (intput = stoi(temp)) >= min && intput <= max)
            return intput;
        cout << "Please enter a number between " << min << " and " << max << "." << endl << endl;
    }
}