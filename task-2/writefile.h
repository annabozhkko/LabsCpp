#include "worker.h"

#include <fstream>

using namespace std;

class Writefile: public Worker{
public:
    vector <string> execute(vector<string> inputFile);
    void validate();
private:
    ofstream fs;
    bool isOpen();
};
