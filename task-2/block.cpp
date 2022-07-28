#include "block.h"

Block::Block(vector<string> block){
    string s = block[0];
    name = block[2];
    number = stoi(block[0]);
    for (int i = 3; i < block.size(); ++i)
        parameters.push_back(block[i]);
}
