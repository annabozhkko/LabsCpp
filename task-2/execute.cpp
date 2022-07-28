#include "execute.h"
#include "fileReader.h"
#include "splitString.h"
#include "workerFabric.h"
#include "exeption.h"

void Executor::readWorkflow(){
    FileReader workflowReader(workflow);
    if(!workflowReader.isOpen()){
        throw CommonError("File Workflow is not opened");
    }
    SplitString splitString;
    string line = workflowReader.getNextLine(); ///desc
    line = workflowReader.getNextLine();
    while(line != "csed"){
        shared_ptr <Block> block = make_shared<Block>(splitString.split(line));
        blocks[block->number] = block;
        line = workflowReader.getNextLine();
    }
    structure = splitString.split(workflowReader.getNextLine());
    for(int i = 0; i < structure.size(); i += 2){
        numbersOfBlocks.push_back(stoi(structure[i]));
    }
}

void Executor::execute(){
    readWorkflow();
    vector<string> inputData;
    for(int i = 0; i < numbersOfBlocks.size(); i++){
        if(i == 0 && blocks[numbersOfBlocks[i]]->name != "readfile")
            throw IncorrectConnection("Incorrect connection readfile");
        if(i > 0 && blocks[numbersOfBlocks[i]]->name == "readfile")
            throw IncorrectConnection("Incorrect connection readfile");
        if(i < numbersOfBlocks.size() - 1 && blocks[numbersOfBlocks[i]]->name == "writefile")
            throw IncorrectConnection("Incorrect connection writefile");
        WorkerFabric workerFabric;
        Worker *worker = workerFabric.create(blocks[numbersOfBlocks[i]]->name, blocks[numbersOfBlocks[i]]->parameters);
        worker->validate();
        inputData = worker->execute(inputData);
        delete worker;
    }
}
