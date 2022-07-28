#include "readfile.h"
#include "exeption.h"

#include <iostream>

bool Readfile::isOpen(){
    if(fs.is_open())
        return 1;
    return 0;
}

bool Readfile::isEof(){
    if(fs.eof())
        return true;
    return false;
}

void Readfile::validate() {
    if(parameters.size() < 1)
        throw NotEnoughParameters("Not enough parameters");
    if(parameters.size() > 1)
        throw TooMuchParameters("Too much parameters");
}

string Readfile::getNextLine(){
    string string;
    getline(fs, string);
    return string;
}

vector <string> Readfile::execute(vector<string> inputFile) {
    fs.open(parameters[0]);
    if(!isOpen())
        throw CommonError("Input file is not opened");
    vector<string> outputData;
    while(!isEof()){
        outputData.push_back(getNextLine());
    }
    fs.close();
    return outputData;
}
