#include "worker.h"

#include <fstream>

using namespace std;

class Readfile: public Worker{
public:
    vector <string> execute(vector<string> inputFile);
    void validate();
private:
    fstream fs;
    bool isOpen();
    string getNextLine();
    bool isEof();
};
