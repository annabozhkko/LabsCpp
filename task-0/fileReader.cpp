#include "fileReader.h"

#include <iostream>

using namespace std;

FileReader::FileReader(string path){
    fs.open(path);
}

bool FileReader::isOpen(){
    if(fs.is_open())
        return 1;
    return 0;
}

bool FileReader::isEof(){
    if(fs.eof())
        return true;
    return false;
}

string FileReader::getNextLine(){
    string string;
    getline(fs, string);
    return string;
}

void FileReader::close(){
    fs.close();
}
