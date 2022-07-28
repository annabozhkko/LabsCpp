#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class FileReader{
    public:
        bool isOpen();
        FileReader(string path);
        string getNextLine();
        void close();
        bool isEof();
private:
        fstream fs;
};
