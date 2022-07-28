#include "randomGamer.h"

#include <iostream>

using namespace std;

RandomGamer::RandomGamer() {
    ships = new Ship[10];
}

RandomGamer::~RandomGamer() {
    delete []ships;
}

void RandomGamer::buildShips(int *field) {
    ships[0].generateShip(4, field);
    for(int i = 1; i < 3; ++i)
        ships[i].generateShip(3, field);
    for(int i = 3; i < 6; ++i)
        ships[i].generateShip(2, field);
    for(int i = 6; i < 10; ++i)
        ships[i].generateShip(1, field);
}

bool RandomGamer::attack(int *field1, int *field2) {
    char x = rand() % 10;
    int y = rand() % 10;
    if(field2[y * 10 + x] == MISS || field2[y * 10 + x] == HITSHIP){
        return attack(field1, field2);
    }
    if(field2[y * 10 + x]  == EMPTY){
        field2[y * 10 + x] = MISS;
        cout  << (char)(x + 'a') << y + 1 << ". " << "Мимо!\n";
        return 0;
    }
    field2[y * 10 + x] = HITSHIP;
    cout << (char)(x + 'a') << y + 1 << ". " << "Ранен!\n";
    return 1;
}
