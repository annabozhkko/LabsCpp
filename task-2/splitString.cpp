#include "splitString.h"

using namespace std;

vector <string> SplitString::split(const string line){
    vector <string> words;
    string word;
    for(int i = 0; i < line.length(); ++i){
        if(line[i] == ' '){
            words.push_back(word);
            word.clear();
            continue;
        }
        word.push_back(line[i]);
    }
    if(word.length())
        words.push_back(word);
    word.clear();
    return words;
}
