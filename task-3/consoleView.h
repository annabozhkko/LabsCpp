#include <string>

#include "gameView.h"
#include "ship.h"

using namespace std;

class ConsoleView: public GameView{
public:
    void showGame(int *field1, int *field2);
};
