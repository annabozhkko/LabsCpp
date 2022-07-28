#include "fileWriter.h"

using namespace std;

FileWriter::FileWriter(string path){
    fs.open(path);
}

bool FileWriter::fileOpen(){
    if(fs.is_open())
        return 1;
    return 0;
}

void FileWriter::writeStatistics(const vector<pair<string, int> > words, const int countWords){
    fs << "word" << "," << "frequency" << "," << "frequency(%)" << "\n";
    for(int i = words.size() - 1; i >= 0; --i){
        float freq = (float)words[i].second / countWords * 100;
        fs << words[i].first << "," << words[i].second << "," << freq << "\n";
    }
    fs.close();
}
