#include <string>
#include <vector>

#pragma once

using namespace std;

class Worker{
public:
    virtual vector <string> execute(vector<string> inputFile) = 0;
    vector<string> parameters;
    virtual void validate() = 0;
    virtual ~Worker() {}
};

