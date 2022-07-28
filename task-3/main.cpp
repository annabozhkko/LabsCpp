#include "gameProcess.h"

using namespace std;

int main(int argc, char **argv){
    if(argc != 3)
        return 0;
    GameProcess gameProcess(argv[1], argv[2]);
    gameProcess.play();
    return 0;
}
