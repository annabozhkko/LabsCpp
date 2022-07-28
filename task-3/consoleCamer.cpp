#include "consoleGamer.h"

#include <iostream>

using namespace std;

ConsoleGamer::ConsoleGamer() {
    ships = new Ship[10];
}

ConsoleGamer::~ConsoleGamer() {
    delete []ships;
}

void ConsoleGamer::buildShips(int *field){
    cout << "Введите координаты 4-палубного коробля(1): ";
    ships[0].buildShipByUser(4, field);
    cout << "Введите координаты 3-палубного коробля(2): ";
    for(int i = 1; i < 3; ++i)
        ships[i].buildShipByUser(3, field);
    cout << "Введите координаты 2-палубного коробля(3): ";
    for(int i = 3; i < 6; ++i)
        ships[i].buildShipByUser(2, field);
    cout << "Введите координаты 1-палубного коробля(4): ";
    for(int i = 6; i < 10; ++i)
        ships[i].buildShipByUser(1, field);
}

bool ConsoleGamer::attack(int *field1, int *field2) {
    char x;
    int y;
    cin >> x >> y;
    x -= 'a';
    y--;
    if(field2[y * 10 + x]  == EMPTY){
        field2[y * 10 + x] = MISS;
        cout << "Мимо!\n";
        return 0;
    }
    if(field2[y * 10 + x] == SHIP){
        field2[y * 10 + x] = HITSHIP;
        cout << "Ранен!\n";
        return 1;
    }
    return 0;
}
