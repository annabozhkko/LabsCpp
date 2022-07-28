#include "gamer.h"

class RandomGamer: public Gamer{
public:
    RandomGamer();
    ~RandomGamer();
    void buildShips(int *field);
    bool attack(int *field1, int *field2);
private:
    Ship *ships;
};
