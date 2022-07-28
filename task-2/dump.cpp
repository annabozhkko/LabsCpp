#include "dump.h"
#include "exeption.h"

bool Dump::isOpen(){
    if(fs.is_open())
        return 1;
    return 0;
}

void Dump::validate() {
    if(parameters.size() < 1)
        throw NotEnoughParameters("Not enough parameters");
    if(parameters.size() > 1)
        throw TooMuchParameters("Too much parameters");
}

vector <string> Dump::execute(vector<string> inputFile) {
    fs.open(parameters[0]);
    if(!isOpen())
        throw CommonError("Output file is not opened");
    for(int i = 0; i < inputFile.size(); ++i){
        fs << inputFile[i] << '\n';
    }
    fs.close();
    return inputFile;
}
