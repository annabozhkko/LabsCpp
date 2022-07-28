#include "gamer.h"
#include "consoleView.h"
#include "consoleGamer.h"
#include "randomGamer.h"
#include "optimalGamer.h"

#include <string>

class GameProcess{
public:
    GameProcess(string name1, string name2);
    ~GameProcess();
    void play();
private:
    Gamer* createGamer(string gamerName);
    string gamerName1;
    string gamerName2;
    int *field1;
    int *field2;
    int countShips1;
    int countShips2;
};
