//
// Created by natha on 12/5/2018.
//

#include "Board.h"

using namespace std;

Board *Board::board;

Board::Board() {
    srand(time(NULL));

    addCity("Vancouver");
    addCity("Calgary");
    addCity("Winnipeg");
    addCity("Sault St. Marie");
    addCity("Montreal");
    addCity("Boston");
    addCity("Toronto");
    addCity("Duluth");
    addCity("Helena");
    addCity("Seattle");
    addCity("Portland");
    addCity("New York");
    addCity("Pittsburgh");
    addCity("Chicago");
    addCity("Omaha");
    addCity("Denver");
    addCity("Salt Lake City");
    addCity("San Francisco");
    addCity("Las Vegas");
    addCity("Los Angeles");
    addCity("Phoenix");
    addCity("Santa Fe");
    addCity("El Paso");
    addCity("Oklahoma City");
    addCity("Dallas");
    addCity("Houston");
    addCity("New Orleans");
    addCity("Little Rock");
    addCity("Kansas City");
    addCity("Saint Louis");
    addCity("Nashville");
    addCity("Atlanta");
    addCity("Raleigh");
    addCity("Washington");
    addCity("Charleston");
    addCity("Miami");

    addRoute("Vancouver", "Seattle", 0, 0, 1);
    addRoute("Seattle", "Portland", 0, 0, 1);
    addRoute("Vancouver", "Calgary", 0, 3);
    addRoute("Seattle", "Calgary", 0, 4);
    addRoute("Calgary", "Helena", 0, 4);
    addRoute("Calgary", "Winnipeg", 7, 6);
    addRoute("Helena", "Winnipeg", 5, 4);
    addRoute("Winnipeg", "Sault St. Marie", 0, 6);
    addRoute("Winnipeg", "Duluth", 8, 4);
    addRoute("Helena", "Duluth", 2, 6);
    addRoute("Duluth", "Sault St. Marie", 0, 3);
    addRoute("Sault St. Marie", "Toronto", 0, 2);
    addRoute("Duluth", "Toronto", 6, 6);
    addRoute("Sault St. Marie", "Montreal", 8, 5);
    addRoute("Toronto", "Montreal", 0, 3);
    addRoute("Montreal", "Boston", 0, 0, 2);
    addRoute("Boston", "New York", 3, 1, 2);
    addRoute("Montreal", "New York", 5, 3);
    addRoute("Toronto", "Pittsburgh", 0, 2);
    addRoute("Pittsburgh", "New York", 7, 4, 2);
    addRoute("New York", "Washington", 8, 2, 2);
    addRoute("Pittsburgh", "Washington", 0, 2);
    addRoute("Washington", "Raleigh", 0, 0, 2);
    addRoute("Pittsburgh", "Raleigh", 0, 2);
    addRoute("Raleigh", "Charleston", 0, 2);
    addRoute("Raleigh", "Atlanta", 0, 0, 2);
    addRoute("Raleigh", "Nashville", 8, 3);
    addRoute("Charleston", "Miami", 6, 4);
    addRoute("Charleston", "Atlanta", 0, 2);
    addRoute("Miami", "Atlanta", 5, 5);
    addRoute("Miami", "New Orleans", 1, 6);
    addRoute("Pittsburgh", "Chicago", 8, 2, 3);
    addRoute("Pittsburgh", "Saint Louis", 3, 5);
    addRoute("Pittsburgh", "Nashville", 3, 4);
    addRoute("Toronto", "Chicago", 7, 4);
    addRoute("Atlanta", "Nashville", 0, 1);
    addRoute("Atlanta", "New Orleans", 2, 3, 4);
    addRoute("Nashville", "Little Rock", 7, 3);
    addRoute("Nashville", "Saint Louis", 0, 2);
    addRoute("Chicago", "Saint Louis", 7, 4, 2);
    addRoute("Chicago", "Omaha", 5, 4);
    addRoute("Chicago", "Duluth", 1, 3);
    addRoute("New Orleans", "Houston", 0, 2);
    addRoute("New Orleans", "Little Rock", 4, 3);
    addRoute("Saint Louis", "Kansas City", 5, 6, 2);
    addRoute("Saint Louis", "Little Rock", 0, 2);
    addRoute("Little Rock", "Dallas", 0, 2);
    addRoute("Little Rock", "Oklahoma City", 0, 2);
    addRoute("Houston", "Dallas", 0, 0, 1);
    addRoute("Houston", "El Paso", 4, 6);
    addRoute("Oklahoma City", "Kansas City", 0, 0, 2);
    addRoute("Oklahoma City", "Dallas", 0, 0, 2);
    addRoute("Oklahoma City", "El Paso", 3, 5);
    addRoute("Oklahoma City", "Denver", 1, 4);
    addRoute("Oklahoma City", "Santa Fe", 5, 3);
    addRoute("Omaha", "Duluth", 0, 0, 2);
    addRoute("Omaha", "Kansas City", 0, 0, 1);
    addRoute("Omaha", "Helena", 1, 5);
    addRoute("Omaha", "Denver", 6, 4);
    addRoute("Kansas City", "Denver", 2, 8, 4);
    addRoute("Dallas", "El Paso", 1, 4);
    addRoute("El Paso", "Santa Fe", 0, 2);
    addRoute("El Paso", "Phoenix", 0, 3);
    addRoute("El Paso", "Los Angeles", 8, 6);
    addRoute("Santa Fe", "Denver", 0, 2);
    addRoute("Santa Fe", "Phoenix", 0, 3);
    addRoute("Denver", "Helena", 4, 4);
    addRoute("Denver", "Salt Lake City", 1, 3, 3);
    addRoute("Denver", "Phoenix", 7, 5);
    addRoute("Helena", "Seattle", 3, 6);
    addRoute("Helena", "Salt Lake City", 6, 3);
    addRoute("Los Angeles", "Phoenix", 0, 3);
    addRoute("Los Angeles", "Las Vegas", 0, 2);
    addRoute("Los Angeles", "San Francisco", 3, 6, 3);
    addRoute("Salt Lake City", "Portland", 5, 6);
    addRoute("Salt Lake City", "San Francisco", 2, 7, 5);
    addRoute("Salt Lake City", "Las Vegas", 2, 3);
    addRoute("Portland", "San Francisco", 4, 6, 5);

    addDestination("Kansas City", "Houston", 5);
    addDestination("Winnipeg", "Houston", 12);
    addDestination("Boston", "Miami", 12);
    addDestination("Chicago", "New Orleans", 7);
    addDestination("Portland", "Nashville", 17);
    addDestination("Montreal", "Atlanta", 9);
    addDestination("Helena", "Los Angeles", 8);
    addDestination("Portland", "Phoenix", 11);
    addDestination("Denver", "El Paso", 4);
    addDestination("San Francisco", "Atlanta", 17);
    addDestination("Calgary", "Phoenix", 13);
    addDestination("Winnipeg", "Little Rock", 11);
    addDestination("Sault St Marie", "Nashville", 8);
    addDestination("Duluth", "Houston", 8);
    addDestination("Sault St Marie", "Oklahoma City", 9);
    addDestination("Duluth", "El Paso", 10);
    addDestination("Vancouver", "Santa Fe", 13);
    addDestination("Montreal", "New Orleans", 13);
    addDestination("Dallas", "New York", 11);
    addDestination("Toronto", "Miami", 10);
    addDestination("Los Angeles", "Miami", 20);
    addDestination("Calgary", "Salt Lake City", 7);
    addDestination("Denver", "Pittsburgh", 11);
    addDestination("New York", "Atlanta", 6);
    addDestination("Chicago", "Santa Fe", 9);
    addDestination("Seattle", "Los Angeles", 9);
    addDestination("Los Angeles", "Chicago", 16);
    addDestination("Los Angeles", "New York", 21);
    addDestination("Seattle", "New York", 22);
    addDestination("Vancouver", "Montreal", 20);

    colorNames = new string[9]();
    colorNames[0] = "Wild";
    colorNames[1] = "Red";
    colorNames[2] = "Orange";
    colorNames[3] = "Yellow";
    colorNames[4] = "Green";
    colorNames[5] = "Blue";
    colorNames[6] = "Purple";
    colorNames[7] = "White";
    colorNames[8] = "Black";

    cardBank = new int[5]();
    wilds = 0;
    for(int i = 0; i < 5; i++) {
        cardBank[i] = 0;
        if(cardBank[i] == 0) wilds++;
    }
    while(wilds >= 3) {
        wilds = 0;
        for(int w = 0; w < 5; w++) {
            if(cardBank[w] == 0) cardBank[w] = getRandomCard();
            if(cardBank[w] == 0) wilds++;
        }
    }
}

Board::~Board() {
    deleteBoard();
    delete[] cardBank;
    delete[] colorNames;
}

Board* Board::getInstance() {
    if(!board) board = new Board();
    return board;
}

void Board::removeInstance() {
    delete board;
}

void Board::addCity(string name) {
    if(findCity(name) == nullptr) cities.push_back(new City(name));
    else cout << name << " already exists! Could not create city!" << endl;
}

void Board::addRoute(string n1, string n2, int color, int distance) {
    if(distance > 0 && color >= 0 && color <= 8) {
        City *c1 = findCity(n1), *c2 = findCity(n2);
        if(c1 != nullptr && c2 != nullptr) {
            auto *temp = new Route(c1, c2, color, distance);
            routes.push_back(temp);
            c1->routes.push_back(temp);
            c2->routes.push_back(temp);
        } else cout << "One of the cities you entered, \"" << n1 << "\" and/or \"" << n2 << "\", does not exist! Could not create route!" << endl;
    } else cout << "Invalid parameters!" << endl;
}

void Board::addRoute(string n1, string n2, int color1, int color2, int distance) {
    if(distance > 0 && color1 >= 0 && color1 <= 8 && color2 >= 0 && color2 <= 8) {
        City *c1 = findCity(n1), *c2 = findCity(n2);
        if(c1 != nullptr && c2 != nullptr) {
            auto *temp1 = new Route(c1, c2, color1, distance);
            auto *temp2 = new Route(c1, c2, color2, distance);
            temp1->route2 = temp2;
            temp2->route2 = temp1;
            routes.push_back(temp1);
            c1->routes.push_back(temp1);
            c2->routes.push_back(temp1);
        } else cout << "One of the cities you entered, \"" << n1 << "\" and/or \"" << n2 << "\", does not exist! Could not create route!" << endl;
    } else cout << "Invalid parameters!" << endl;
}

void Board::addDestination(string city1, string city2, int points) {
    City *c1 = findCity(city1);
    City *c2 = findCity(city2);
    if(c1 && c2) {
        auto *d = new Destination(c1, c2, points);
        destinations.push_back(d);
    }
}

Destination *Board::getRandomDest() {
    //return destinations[9];
    if(!destinations.empty()) {
        int index = rand() % (int) destinations.size();
        Destination *d = destinations[index];
        destinations.erase(destinations.begin() + index);
        return d;
    }
    cout << "Ran out of destinations!" << endl;
    return nullptr;
}

City *Board::findCity(string name) {
    for(City *city : cities)
        if(city->name == name) return city;
    return nullptr;
}

Route *Board::findRoute(string c1, string c2) {
    for(Route *r : routes) {
        if((r->cities[0]->name == c1 && r->cities[1]->name == c2) || (r->cities[1]->name == c1 && r->cities[0]->name == c2)) {
            return r;
        }
    }
    return nullptr;
}

Route *Board::findRoute(City *c1, City *c2) {
    for(Route *r : routes) {
        if((r->cities[0] == c1 && r->cities[1] == c2) || (r->cities[1] == c1 && r->cities[0] == c2)) {
            return r;
        }
    }
    return nullptr;
}

vector<City*> Board::getCities() {
    return cities;
}

string Board::getCardBankString() {
    string bank = colorNames[cardBank[0]] + ", " + colorNames[cardBank[1]] + ", " + colorNames[cardBank[2]]
            + ", " + colorNames[cardBank[3]] + ", " + colorNames[cardBank[4]];
    return bank;
}

int Board::getBankOrRand(int color) {
    int found = false;
    for(int i = 0; i < 5; i++) {
        if(cardBank[i] == color) {
            found = true;
            if(color == 0) wilds--;
            cardBank[i] = getRandomCard();
            if(cardBank[i] == 0) wilds++;
            while(wilds >= 3) {
                wilds = 0;
                for(int w = 0; w < 5; w++) {
                    if(cardBank[w] == 0) cardBank[w] = getRandomCard();
                    if(cardBank[w] == 0) wilds++;
                }
            }
            break;
        }
    }
    if(!found) color = getRandomCard();
    return color;
}

int Board::getRandomCard() {
    int val = rand() % 110;
    switch(val) {
        case 0 ... 13:
            return 0;
        case 14 ... 25:
            return 1;
        case 26 ... 37:
            return 2;
        case 38 ... 49:
            return 3;
        case 50 ... 61:
            return 4;
        case 62 ... 73:
            return 5;
        case 74 ... 85:
            return 6;
        case 86 ... 97:
            return 7;
        case 98 ... 109:
            return 8;
        default:
            cout << "Weird error. Here have a wild." << endl;
            return 0;
    }
}

void Board::reset(int d) {
    for(City *c : cities) {
        c->distance = d;
        c->parent = nullptr;
    }
}

void Board::deleteBoard() {
    for(Route *route : routes) {
        delete route;
    }
    for(City *city : cities) {
        delete city;
    }
    for(Destination *destination : destinations) {
        delete destination;
    }
}