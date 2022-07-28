#include "worker.h"

#include <string>
#include <vector>

using namespace std;

class Grep: public Worker{
public:
    vector <string> execute(vector<string> inputFile);
    void validate();
private:
    bool isWordInText(string line);
};
