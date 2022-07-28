#include "replace.h"
#include "exeption.h"

void Replace::validate() {
    if(parameters.size() < 2)
        throw NotEnoughParameters("Not enough parameters");
    if(parameters.size() > 2)
        throw TooMuchParameters("Too much parameters");
}

vector <string> Replace::execute(vector<string> inputFile) {
    for(int i = 0; i < inputFile.size(); ++i){
        while(inputFile[i].find(parameters[0]) != -1){
            inputFile[i].replace(inputFile[i].find(parameters[0]), parameters[0].length(), parameters[1]);
        }
    }
    return inputFile;
}
