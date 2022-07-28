#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class FileWriter{
    public:
        bool fileOpen();
        FileWriter(string path);
        void writeStatistics(const vector<pair<string, int> > words, const int countWords);

    private:
        ofstream fs;
};
