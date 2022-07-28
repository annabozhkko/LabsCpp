#include "sort.h"
#include "exeption.h"

#include <algorithm>

void Sort::validate() {
    if(parameters.size() > 0)
        throw TooMuchParameters("Too much parameters");
}

int comp(const string &a, const string &b){
    return (a > b);
}

vector <string> Sort::execute(vector<string> inputFile){
    sort(begin(inputFile), end(inputFile));
    return inputFile;
}
