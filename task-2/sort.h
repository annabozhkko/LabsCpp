#include "worker.h"

class Sort: public Worker{
public:
    vector <string> execute(vector<string> inputFile);
    void validate();
};
