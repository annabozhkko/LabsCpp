#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>

#include "block.h"

using namespace std;

class Executor{
public:
    Executor(string fileWorkflow){workflow = fileWorkflow;}
    void execute();
private:
    string workflow;
    map<int, shared_ptr<Block>> blocks;
    vector<int> numbersOfBlocks;
    void readWorkflow();
    vector<string> structure;
};
