#include "worker.h"

#include <string>

using namespace std;

class Replace: public Worker{
public:
    vector <string> execute(vector<string> inputFile);
    void validate();
};
