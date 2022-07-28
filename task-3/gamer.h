#pragma once

#include "ship.h"

class Gamer{
public:
    virtual void buildShips(int *field) = 0;
    virtual bool attack(int *field1, int *field2) = 0;
    virtual ~Gamer() {}
private:
    Ship *ships;
};

