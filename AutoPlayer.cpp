//
// Created by natha on 12/7/2018.
//

#include "AutoPlayer.h"

using namespace std;

struct AutoPlayer::PQ {
public:
    City *pop() {
        if(empty()) return nullptr;
        int index = 0;
        for(int i = 1; i < vertices.size(); i++) {
            if(vertices[i]->distance < vertices[index]->distance) index = i;
        }
        City *temp = vertices[index];
        vertices.erase(vertices.begin() + index);
        return temp;
    }

    void push(City *c) {
        vertices.push_back(c);
    }

    bool empty() {
        return vertices.empty();
    }

private:
    std::vector<City*> vertices;
};

AutoPlayer::AutoPlayer(int num): Player(num) {
    hand = new int[9]();
    dest = b->getRandomDest();
    hand[b->getRandomCard()]++;
    hand[b->getRandomCard()]++;
    hand[b->getRandomCard()]++;
    hand[b->getRandomCard()]++;
}

AutoPlayer::~AutoPlayer() {
    delete[] hand;
}

void AutoPlayer::playTurn() {
    cout << "Player " << getPlayerNumber() << "'s turn. Trains: " << getNumTrains() << ", Current score: " << getScore() << endl;
    printHand();

    Route *r = findWorkingRoute(dest);
    if(r && r->player == getPlayerNumber()) { //Are we done with the destination?
        cout << "Completed Destination! (" << dest->c1->name << " to " << dest->c2->name << ")" << endl;
        increaseScore(dest->points);
        dest = nullptr;
    } else if(!r) { //Is the destination impossible?
        cout << "No possible paths to complete destination!" << endl;
        increaseScore(dest->points * -1);
        dest = nullptr;
    }

    if(dest == nullptr) { //If we need a new destination
        dest = b->getRandomDest();
        cout << "New Destination: " << dest->c1->name << " to " << dest->c2->name << ", " << dest->points << " points." << endl;
    } else {
        cout << "Destination: " << dest->c1->name << " to " << dest->c2->name << ", " << dest->points << " points." << endl;
        int color = r->color;
        if(r->color == 0) color = getBestColorIndex(hand, r->dist);

        if(getNumTrains() >= r->dist && hand[color] >= r->dist) { //Play a route with just that color
            cout << "Player " << getPlayerNumber() << " played " << r->dist << " " << b->colorNames[color] << " card(s) to go from ";
            cout << r->cities[0]->name << " to " << r->cities[1]->name << endl;
            hand[color] -= r->dist;
            playTrains(r->dist);
            r->player = getPlayerNumber();
        } else if(getNumTrains() >= r->dist && hand[color] + hand[0] >= r->dist) { //Play a route with colors and wilds
            cout << "Player " << getPlayerNumber() << " played " << hand[color] << " " << b->colorNames[color] << " card(s) and ";
            cout << (r->dist - hand[color]) << " Wild card(s) to go from " << r->cities[0]->name << " to " << r->cities[1]->name << endl;
            hand[0] -= (r->dist - hand[color]);
            hand[color] = 0;
            playTrains(r->dist);
            r->player = getPlayerNumber();
        } else { //draw cards
            cout << "Drawing for " << b->colorNames[color] << " cards for " << r->cities[0]->name << " to " << r->cities[1]->name << endl;
            cout << "Bank: " << b->getCardBankString() << endl;
            int c1 = b->getBankOrRand(color), c2 = b->getBankOrRand(color);
            hand[c1]++;
            hand[c2]++;
            cout << "Player " << getPlayerNumber() << " drew a " << b->colorNames[c1] << " card and a " << b->colorNames[c2] << " card." << endl;
        }

    }
    cout << endl;
}

Route *AutoPlayer::findWorkingRoute(Destination *dest) {
    vector<Route*> finalPath;

    City *c1 = dest->c1;
    b->reset(999999);
    c1->distance = 0;
    PQ q;
    for(City *city : b->getCities()) q.push(city);
    while(!q.empty()) {
        City *city = q.pop();

        if(city->name == dest->c2->name) { //if we've reached our destination
            if(city->distance == 999999) return nullptr; //if it's impossible to get there, return nullptr
            else {
                while(city->parent != nullptr) { //otherwise add all the routes in the path to a vector for later
                    finalPath.push_back(city->parent);
                    if(city == city->parent->cities[0]) city = city->parent->cities[1];
                    else city = city->parent->cities[0];
                }
            }
            break;
        } else { //if we haven't reached the destination
            for(int i = 0; i < city->routes.size(); i++) { //loop through the routes out of this city
                Route *r = city->routes[i];
                if(r->route2 && getEdgeWeight(r->route2, hand) < getEdgeWeight(r, hand)) r = r->route2; //choose the shorter route if it's a double

                int d = city->distance + getEdgeWeight(r, hand);
                City *newCity = r->cities[0]; //make sure we're not pointing to the current city
                if(newCity == city) newCity = r->cities[1];

                if(d < newCity->distance) { //if we have a shorter path, update the adjacent city
                    newCity->distance = d;
                    newCity->parent = r;
                }
            }
        }
    }

    Route *final = nullptr;
    for(Route *route : finalPath) {
        if(route->player != getPlayerNumber()) {
            if(!final) final = route;
            else if(getEdgeWeight(route, hand) < getEdgeWeight(final, hand)) final = route;
        }
    }
    if(!final) final = finalPath[0];

    return final;
}

int AutoPlayer::getEdgeWeight(City *c1, City *c2, int *hand) {
    Route *r = b->findRoute(c1, c2);
    getEdgeWeight(r, hand);
}

int AutoPlayer::getEdgeWeight(Route *r, int*hand) {
    if(r) {
        if(r->player == getPlayerNumber()) return 0; //You already own this route
        if(r->player != 0) return 999999; //Someone else already owns this route
        if(r->color == 0) return 2 + max(r->dist - (hand[getBestColorIndex(hand, r->dist)] + hand[0]), 0); //If it's a grey route use whatever you have most of
        else return 2 + max(r->dist - (hand[r->color] + hand[0]), 0); //otherwise use the color of the route
    }
    cout << "Ahhhhh! Bad Edge!" << endl;
    return 999999;
}

int AutoPlayer::getBestColorIndex(int *cards, int dist) {
    int best = 1;
    for(int i = 2; i < 9; i++) {
        if(cards[best] < dist && cards[i] < dist) {
            if(cards[i] > cards[best]) best = i;
        } else if(cards[best] >= dist && cards[i] >= dist) {
            if(cards[i] < cards[best]) best = i;
        } else if(cards[i] > cards[best]) best = i;
    }
    return best;
}

void AutoPlayer::printHand() {
    cout << "Hand: ";
    for(int i = 0; i < 9; i++) {
        if(hand[i] != 0) cout << hand[i] << " " << b->colorNames[i] << ", ";
    }
    cout << endl;
}