#pragma once

enum GAME{
    EMPTY,  ///
    MISS,   /// .
    HITSHIP,  /// x
    SHIP  /// #
};

class Ship{
public:
    Ship();
    ~Ship();
    void generateShip(int n, int *field);
    void buildShipByUser(int n, int *field);
private:
    int size;
    bool dir;
    char *x;
    int *y; ///координаты (x, y)
    bool isEmptyField(int *field, char x, int y);
};
