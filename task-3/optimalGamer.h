#include "gamer.h"

class OptimalGamer: public Gamer{
public:
    OptimalGamer();
    ~OptimalGamer();
    void buildShips(int *field);
    bool attack(int *field1, int *field2);
private:
    Ship *ships;
    int hitLastShip(int *field2);
    bool isHitShip();
    void changeDirection();
    bool hitShip;
    int dir;
    char *x;
    int *y; /// координаты (x, y)
    int index;
};
