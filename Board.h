//
// Created by natha on 12/5/2018.
//

#ifndef TRAP_BOARD_H
#define TRAP_BOARD_H

#include <vector>
#include <iostream>
#include <ctime>

struct Route;
class Board;

struct City {
    std::string name;
    std::vector<Route*> routes;
    int distance;
    Route *parent;

    explicit City(std::string n) {
        name = std::move(n);
        distance = 0;
        parent = nullptr;
    }
};

struct Route {
    City *cities[2] = {nullptr, nullptr};
    Route *route2;
    int dist;
    int color; //0 = Grey, 1 = Red, 2 = Orange, 3 = Yellow, 4 = Green, 5 = Blue, 6 = Pink, 7 = White, 8 = Black
    int player; //0 = no player

    Route(City *c1, City *c2, int c, int d) {
        cities[0] = c1;
        cities[1] = c2;
        dist = d;
        color = c;
        player = 0;
        route2 = nullptr;
    }
};

struct Destination {
    City *c1, *c2;
    int points;

    Destination(City *city1, City *city2, int p) {
        c1 = city1;
        c2 = city2;
        points = p;
    }
};

class Board {
public:
    Board();
    ~Board();

    std::string getCardBankString();
    int getBankOrRand(int);
    int getRandomCard();
    Destination *getRandomDest();

    Route *findRoute(std::string, std::string);
    Route *findRoute(City*, City*);
    City *findCity(std::string);
    std::vector<City*> getCities();

    void reset(int);

    static Board *getInstance();
    static void removeInstance();

    std::string *colorNames;

private:
    void addCity(std::string);
    void addRoute(std::string, std::string, int, int);
    void addRoute(std::string, std::string, int, int, int);
    void addDestination(std::string, std::string, int);
    void deleteBoard();

    std::vector<City*> cities;
    std::vector<Route*> routes;
    std::vector<Destination*> destinations;
    int *cardBank;
    int wilds;

    static Board *board;
};


#endif //TRAP_BOARD_H
