#include <string>

#include "gamer.h"

using namespace std;

class ConsoleGamer: public Gamer{
public:
    ConsoleGamer();
    ~ConsoleGamer();
    void buildShips(int *field);
    bool attack(int *field1, int *field2);
private:
    Ship *ships;
};
