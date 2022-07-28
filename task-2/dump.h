#include "worker.h"

#include <string>
#include <fstream>

using namespace std;

class Dump: public Worker{
public:
    vector <string> execute(vector<string> inputFile);
    void validate();
private:
    fstream fs;
    bool isOpen();
};
