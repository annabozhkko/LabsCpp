#include <iostream>

using namespace std;

class GameView{
public:
    virtual void showGame(int *field1, int *field2) = 0;
};
