#include "grep.h"
#include "splitString.h"
#include "exeption.h"

bool Grep::isWordInText(string line) {
    SplitString splitString;
    vector<string> words = splitString.split(line);
    for(int i = 0; i < words.size(); ++i) {
        if(words[i] == parameters[0])
            return 1;
    }
    return 0;
}

void Grep::validate() {
    if(parameters.size() < 1)
        throw NotEnoughParameters("Not enough parameters");
    if(parameters.size() > 1)
        throw TooMuchParameters("Too much parameters");
}

vector <string> Grep::execute(vector<string> inputFile) {
    vector<string> outputData;
    for(int i = 0; i < inputFile.size(); ++i){
        if(isWordInText(inputFile[i]))
            outputData.push_back(inputFile[i]);
    }
    return outputData;
}
