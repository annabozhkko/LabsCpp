#include "ship.h"

#include <iostream>

using namespace std;

Ship::Ship() {
    x = new char[4];
    y = new int[4];
}

Ship::~Ship() {
    delete []x;
    delete []y;
}

bool Ship::isEmptyField(int *field, char x, int y){
    if(x > 9 || y > 9)
        return 0;
    if(field[y * 10 + x] != EMPTY) {
        return 0;
    }
    if(x != 0 && x != 9 && (field[(y - 1) * 10 + x] != EMPTY || field[(y + 1) * 10 + x] != EMPTY)) {
        return 0;
    }
    if(y != 0 && y != 9 && (field[y * 10 + x - 1] != EMPTY || field[y * 10 + x + 1] != EMPTY)) {
        return 0;
    }
    if(x != 0 && x != 9 && y != 0 && y != 9 && (field[(y - 1) * 10 + x - 1] != EMPTY || field[(y - 1) * 10 + x + 1] != EMPTY)) {
        return 0;
    }
    if(x != 0 && x != 9 && y != 0 && y != 9 && (field[(y + 1) * 10 + x - 1] != EMPTY || field[(y + 1) * 10 + x + 1] != EMPTY)) {
        return 0;
    }
    return 1;
}

void Ship::generateShip(int n, int *field) {
    size = n;
    dir = rand() % 2; ///1 - вниз, 0 - вправо
    while(1){
        int i = 0;
        x[i] = rand() % 10;
        y[i] = rand() % 10;
        while(i < size){
            if(!isEmptyField(field, x[i], y[i]))
                break;
            i++;
            if(dir) {
                x[i] = x[i - 1];
                y[i] = y[i - 1] + 1;
            }
            else {
                y[i] = y[i - 1];
                x[i] = x[i - 1] + 1;
            }
        }
        if(i < size)
            continue;
        break;
    }
    for(int i = 0; i < size; ++i)
        field[y[i] * 10 + x[i]] = SHIP;
}

void Ship::buildShipByUser(int n, int *field) {
    size = n;
    int i = 0;
    while(i < size){
        cin >> x[i] >> y[i];
        x[i] -= 'a';
        y[i] -= 1;
        if(!isEmptyField(field, x[i], y[i])){
            i = -1;
            cout << "Нельзя построить здесь корабль\n";
        }
        i++;
    }
    for(int j = 0; j < size; ++j){
        field[y[j] * 10 + x[j]] = SHIP;
    }
}
