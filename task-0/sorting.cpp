#include "sorting.h"

#include <iostream>

bool comp(const pair<string, int> &a, const pair<string, int> &b){
    return (a.second < b.second);
}

void Sorting::sort(vector<pair<string, int> > &words){
   std::sort(words.begin(), words.end(), comp);
}
