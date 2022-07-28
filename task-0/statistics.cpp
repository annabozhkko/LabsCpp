#include "statistics.h"

#include <iostream>

using namespace std;

Statistics::Statistics(){
    countWords = 0;
}

void Statistics::statisticsWords(string word){
    if(word[0] >= 'A' && word[0] <= 'Z' && (word[1] >= 'a' && word[1] <= 'z' || word.length() == 1))
        word[0] += 'a' - 'A';

    map <string, int> :: iterator it;
    it = mapWords.find(word);
    if(it != mapWords.end())
        mapWords[word]++;
    else
        mapWords[word] = 1;

    countWords++;
}

int Statistics::getCountWords(){
    return countWords;
}

vector <pair<string, int> > Statistics::getStatistics(){
    vector <pair<string, int> > statistics(mapWords.begin(), mapWords.end());
    return statistics;
}
