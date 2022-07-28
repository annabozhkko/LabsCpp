#include "fileReader.h"
#include "fileWriter.h"
#include "sorting.h"
#include "splitString.h"
#include "statistics.h"

using namespace std;

int main(int argc, char **argv){
    if(argc != 3)
        return 0;
    FileReader fileReader(argv[1]);
    if(!fileReader.isOpen()){
        cout << "Не удается открыть файл: in.txt";
        return 0;
    }

    vector<string> strings;
    SplitString splitString;
    Statistics statistics;

     while(!fileReader.isEof()){
        string line = fileReader.getNextLine();
        vector<string> words = splitString.split(line);
        for(int i = 0; i < words.size(); ++i){
            statistics.statisticsWords(words[i]);
        }
     }
    fileReader.close();
    vector <pair<string, int> > statisticsWords = statistics.getStatistics();

    Sorting sorting;
    sorting.sort(statisticsWords);

    FileWriter fileWriter(argv[2]);
    if(!fileWriter.fileOpen()){
        cout << "Не удается открыть файл: out.csv";
        return 0;
    }
    fileWriter.writeStatistics(statisticsWords, statistics.getCountWords());

    return 0; 
}
