//
// Created by natha on 12/7/2018.
//

#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(int num): Player(num) {}

void HumanPlayer::playTurn() {
    cout << "Player " << getPlayerNumber() << "'s turn. Trains: " << getNumTrains() << ", Current score: " << getScore() << endl;
    bool doneWithTurn = false;
    while(!doneWithTurn) {
        int option = getIntput("Options:\n1. Cards\n2. Trains\n\nWhat do you want to do? ", 1, 2);

        if(option == 1) {
            cout << "Bank is: " << b->getCardBankString() << endl;
            cout << "What color do you want?\n(0 = Wild, 1 = Red, 2 = Orange, 3 = Yellow, 4 = Green, 5 = Blue, 6 = Purple, 7 = White, 8 = Black, 9 = Random, 10 = Cancel)" <<  endl;
            int color1  = getIntput("First card: ", 0, 10);
            if(color1 == 10) continue;

            int color2 = -1;
            if(color1 != 0) color2 = getIntput("Second card (no wilds): ", 1, 9);
            if(color2 == 10) continue;

            if(color1 == 9) color1 = b->getRandomCard();
            else color1 = b->getBankOrRand(color1);

            if(color2 != -1) {
                if(color2 == 9) color2 = b->getRandomCard();
                else color2 = b->getBankOrRand(color2);
            }
            cout << "You drew a " << b->colorNames[color1] << " card";
            if(color2 != -1) cout << " and a " << b->colorNames[color2] << " card" << endl;
            else cout << endl;

            doneWithTurn = true;
        } else {
            bool done = false;
            while(!done) {
                cout << endl;
                string city1, city2;
                cout << "Enter one of the cities (or \"quit\" to cancel): ";
                getline(cin, city1);
                if(city1 == "quit") break;

                cout << "Enter the other city (or \"quit\" to cancel): ";
                getline(cin, city2);
                if(city2 == "quit") break;

                Route *route = b->findRoute(city1, city2);
                if(route) {
                    if(route->route2) { //If it is a double route
                        Route *route2 = route->route2;
                        if(route2->player == 0 && route->player == 0) { //If both are open
                            if(route->color == 0) { //If it is grey, it doesn't matter, both routes are the same
                                if(getNumTrains() >= route->dist) {
                                    if(route->color == 0) cout << "Play " << route->dist << " of any color card." << endl;
                                    else cout << "Play " << route->dist << " " << b->colorNames[route->color] << " card(s)." << endl;
                                    route->player = getPlayerNumber();
                                    playTrains(route->dist);
                                    doneWithTurn = true;
                                    done = true;
                                } else cout << "You don't have enough trains for this route!" << endl;
                            } else { //If it isn't grey you need to choose a color
                                cout << "Which color would you like to claim? 1 for " << b->colorNames[route->color] << ", 2 for " << b->colorNames[route2->color] << ": ";
                                int color = getIntput("", 1, 2);
                                if(color == 1) { //went with route 1
                                    if(getNumTrains() >= route->dist) {
                                        if(route->color == 0) cout << "Play " << route->dist << " of any color card." << endl;
                                        else cout << "Play " << route->dist << " " << b->colorNames[route->color] << " card(s)." << endl;
                                        route->player = getPlayerNumber();
                                        playTrains(route->dist);
                                        doneWithTurn = true;
                                        done = true;
                                    } else cout << "You don't have enough trains for this route!" << endl;
                                } else { //went with route 2
                                    if(getNumTrains() >= route2->dist) {
                                        if(route2->color == 0) cout << "Play " << route2->dist << " of any color card." << endl;
                                        else cout << "Play " << route2->dist << " " << b->colorNames[route2->color] << " card(s)." << endl;
                                        route2->player = getPlayerNumber();
                                        playTrains(route2->dist);
                                        doneWithTurn = true;
                                        done = true;
                                    } else cout << "You don't have enough trains for this route!" << endl;
                                }
                            }
                        } else if(route->player == getPlayerNumber() || route->player == getPlayerNumber()) { //If you already own one of the routes
                            cout << "You already claimed one of these tracks! Try again!" << endl;
                        } else if(route->player == 0) { //If the first route is open but nor the second
                            if(getNumTrains() >= route->dist) {
                                if(route->color == 0) cout << "Play " << route->dist << " of any color card." << endl;
                                else cout << "Play " << route->dist << " " << b->colorNames[route->color] << " card(s)." << endl;
                                route->player = getPlayerNumber();
                                playTrains(route->dist);
                                doneWithTurn = true;
                                done = true;
                            } else cout << "You don't have enough trains for this route!" << endl;
                        } else if(route2->player == 0) { //If the second route is open but not the first
                            if(getNumTrains() >= route2->dist) {
                                if(route2->color == 0) cout << "Play " << route2->dist << " of any color card." << endl;
                                else cout << "Play " << route2->dist << " " << b->colorNames[route2->color] << " card(s)." << endl;
                                route2->player = getPlayerNumber();
                                playTrains(route2->dist);
                                doneWithTurn = true;
                                done = true;
                            } else cout << "You don't have enough trains for this route!" << endl;
                        } else cout << "Both of these tracks are already claimed! Try again!" << endl;
                    } else { //If this is a single route
                        if(route->player == 0) { //If it is open
                            if(getNumTrains() >= route->dist) {
                                if(route->color == 0) cout << "Play " << route->dist << " of any color card." << endl;
                                else cout << "Play " << route->dist << " " << b->colorNames[route->color] << " card(s)." << endl;
                                route->player = getPlayerNumber();
                                playTrains(route->dist);
                                doneWithTurn = true;
                                done = true;
                            } else cout << "You don't have enough trains for this route!" << endl;
                        } else {
                            if(route->player == getPlayerNumber()) cout << "You already claimed this route! Try again!" << endl;
                            else cout << "This route is already claimed by another player! Try again!" << endl;
                        }
                    }
                } else cout << "No such route found! Try again!" << endl << endl;
            }
        }
    }
    cout << endl << endl;
}