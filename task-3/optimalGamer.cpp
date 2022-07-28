#include "optimalGamer.h"

#include <iostream>

using namespace std;

OptimalGamer::OptimalGamer() {
    ships = new Ship[10];
    hitShip = 0;
    index = 0;
    x = new char[4];
    y = new int[4];
}

OptimalGamer::~OptimalGamer() {
    delete []ships;
    delete []x;
    delete []y;
}

void OptimalGamer::buildShips(int *field) {
    ships[0].generateShip(4, field);
    for(int i = 1; i < 3; ++i)
        ships[i].generateShip(3, field);
    for(int i = 3; i < 6; ++i)
        ships[i].generateShip(2, field);
    for(int i = 6; i < 10; ++i)
        ships[i].generateShip(1, field);
}

bool OptimalGamer::isHitShip() {
    return hitShip;
}

void OptimalGamer::changeDirection() {
    if(dir == 0){
        x[index]++;
        y[index] = y[index - 1];
    }
    if(dir == 1){
        x[index]--;
        y[index] = y[index - 1];
    }
    if(dir == 2){
        y[index]--;
        x[index] = x[index - 1];
    }
    if(dir == 3){
        y[index]++;
        x[index] = x[index - 1];
    }
}

int OptimalGamer::hitLastShip(int *field2) {
    if(x[index] < 0 || x[index] > 9 || y[index] < 0 || y[index] > 9){
        dir++;
        return -1;
    }
    changeDirection();
    if(field2[y[index] * 10 + x[index]] == MISS){
        dir++;
        return -1;
    }
    if(field2[y[index] * 10 + x[index]] == HITSHIP)
        return -1;
    if(field2[y[index] * 10 + x[index]] == EMPTY){
        dir++;
        field2[y[index] * 10 + x[index]] = MISS;
        cout  << (char)(x[index] + 'a') << y[index] + 1 << ". " << "Мимо!\n";
        return 0;
    }
    cout << (char)(x[index] + 'a') << y[index] + 1 << ". " << "Ранен!\n";
    field2[y[index] * 10 + x[index]] = HITSHIP;
    index++;
    x[index] = x[index - 1];
    y[index] = y[index - 1];
    return 1;
}

bool OptimalGamer::attack(int *field1, int *field2){
    if(dir == 4) { ///корабль убит
        hitShip = 0;
    }
    if(isHitShip()){
        int a = hitLastShip(field2);
        if(a == -1)
            return attack(field1, field2);
        return a;
    }
    x[0] = rand() % 10;
    y[0] = rand() % 10;
    if(field2[y[0] * 10 + x[0]] == MISS || field2[y[0] * 10 + x[0]] == HITSHIP)
        return attack(field1, field2);
    if(field2[y[0] * 10 + x[0]] == EMPTY) {
        field2[y[0] * 10 + x[0]] = MISS;
        cout  << (char)(x[0] + 'a') << y[0] + 1 << ". " << "Мимо!\n";
        return 0;
    }
    hitShip = 1;
    dir = 0;   ///0 - вправо, 1 - влево, 2 - вверх, 3 - вниз
    field2[y[0] * 10 + x[0]] = HITSHIP;
    cout << (char)(x[0] + 'a') << y[0] + 1 << ". " << "Ранен!\n";
    index = 1;
    x[1] = x[0];
    y[1] = y[0];
    return 1;
}
