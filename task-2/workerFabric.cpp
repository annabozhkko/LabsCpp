#include "workerFabric.h"
#include "exeption.h"

Worker* WorkerFabric::create(string blockTitle, vector<string> parameters) {
    Worker *worker;
    if(blockTitle == "readfile")
        worker = new Readfile();
    else if(blockTitle == "writefile")
        worker = new Writefile();
    else if(blockTitle == "sort")
        worker = new Sort();
    else if(blockTitle == "replace")
        worker = new Replace();
    else if(blockTitle == "dump")
        worker = new Dump();
    else if(blockTitle == "grep")
        worker = new Grep();
    else
        throw UnknownBlock("Unknown block");

    worker->parameters = parameters;
    return worker;
}
