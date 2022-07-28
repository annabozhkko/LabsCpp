#include <map>
#include <string.h>
#include <vector>

using namespace std;

class Statistics{
    public:
        Statistics();
        void statisticsWords(string word);
        vector <pair<string, int> > getStatistics();
        int getCountWords();

    private:
        map <string, int> mapWords;
        int countWords;
};
