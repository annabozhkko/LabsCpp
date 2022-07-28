#include <string>
#include <vector>

using namespace std;

class Block{
public:
    Block(vector<string> block);
    string name;
    vector<string> parameters;
    int number;
};
