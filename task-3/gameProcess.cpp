#include "gameProcess.h"

GameProcess::GameProcess(string name1, string name2) {
    gamerName1 = name1;
    gamerName2 = name2;
    field1 = new int[10 * 10];
    field2 = new int[10 * 10];
    for(int i = 0; i < 10 * 10; ++i){
        field1[i] = EMPTY;
        field2[i] = EMPTY;
    }
}

GameProcess::~GameProcess() {
    delete []field1;
    delete []field2;
}

Gamer* GameProcess::createGamer(string gamerName) {
    Gamer *gamer;
    if(gamerName == "Console")
        gamer = new ConsoleGamer();
    if(gamerName == "Random")
        gamer = new RandomGamer();
    if(gamerName == "Optimal")
        gamer = new OptimalGamer();
    return gamer;
}

void GameProcess::play() {
    ConsoleView consoleView;
    Gamer *gamer1 = createGamer(gamerName1);
    Gamer *gamer2 = createGamer(gamerName2);
    consoleView.showGame(field1, field2);
    gamer1->buildShips(field1);
    consoleView.showGame(field2, field1);
    gamer2->buildShips(field2);
    countShips1 = 20;
    countShips2 = 20;
    while(countShips1 > 0 && countShips2 > 0){
        consoleView.showGame(field1, field2);
        while(gamer1->attack(field1, field2) && countShips2 > 0 && countShips1 > 0){
            consoleView.showGame(field1, field2);
            countShips2--;
        }
        consoleView.showGame(field2, field1);
        while(gamer2->attack(field2, field1) && countShips2 > 0 && countShips1 > 0){
            consoleView.showGame(field2, field1);
            countShips1--;
        }
    }
    if(countShips1 == 0)
        cout << "Игрок 2 выиграл";
    else
        cout << "Игрок 1 выиграл";

    delete gamer1;
    delete gamer2;
}
