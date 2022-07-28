#include <gtest/gtest.h>

#include "../execute.h"
#include "../exeption.h"

using namespace std;

TEST(Workflow1, Workflow){
    ofstream fout;
    fout.open("workflow.txt");
    fout << "desc\n";
    fout << "1 = readfile in.txt\n";
    fout << "2 = writefile out.txt\n";
    fout << "3 = sort\n";
    fout << "10 = replace workflow task\n";
    fout << "4 = grep task\n";
    fout << "csed\n";
    fout << "1 -> 3 -> 10 -> 3 -> 2\n";
    fout.close();

    ofstream input;
    input.open("in.txt");
    input << "anna bozhko oop\n";
    input << "workflow task\n";
    input << "qwerty qwerty\n";
    input << "abcd";
    input.close();

    Executor executor("workflow.txt");
    try{
        executor.execute();
    }
    catch(UnknownBlock &error){
        error.printMessage();
    }
    catch(IncorrectConnection &error){
        error.printMessage();
    }
    catch(TooMuchParameters &error){
        error.printMessage();
    }
    catch(NotEnoughParameters &error){
        error.printMessage();
    }
    catch(ValidationError &error){
        error.printMessage();
    }
    catch(CommonError &error){
        error.printMessage();
    }

    fstream output;
    output.open("out.txt");
    string line;
    getline(output, line);
    EXPECT_EQ(line, "abcd");
    getline(output, line);
    EXPECT_EQ(line, "anna bozhko oop");
    getline(output, line);
    EXPECT_EQ(line, "qwerty qwerty");
    getline(output, line);
    EXPECT_EQ(line, "task task");
    output.close();
}

TEST(Workflow2, Workflow){
    ofstream fout;
    fout.open("workflow.txt");
    fout << "desc\n";
    fout << "1 = readfile in.txt\n";
    fout << "2 = writefile out.txt\n";
    fout << "3 = sort\n";
    fout << "10 = replace workflow task\n";
    fout << "4 = grep task\n";
    fout << "csed\n";
    fout << "4 -> 3 -> 10 -> 3 -> 2\n";
    fout.close();

    ofstream input;
    input.open("in.txt");
    input << "anna bozhko oop\n";
    input << "workflow task\n";
    input << "qwerty qwerty\n";
    input << "abcd";
    input.close();

    Executor executor("workflow.txt");
    EXPECT_THROW(executor.execute(), IncorrectConnection);
}

TEST(Workflow3, Workflow){
    ofstream fout;
    fout.open("workflow.txt");
    fout << "desc\n";
    fout << "1 = readfile in.txt\n";
    fout << "2 = writefile out.txt\n";
    fout << "3 = sort\n";
    fout << "10 = replace workflow\n";
    fout << "4 = grep task\n";
    fout << "csed\n";
    fout << "1 -> 3 -> 10 -> 3 -> 2\n";
    fout.close();

    ofstream input;
    input.open("in.txt");
    input << "anna bozhko oop\n";
    input << "workflow task\n";
    input << "qwerty qwerty\n";
    input << "abcd";
    input.close();

    Executor executor("workflow.txt");
    EXPECT_THROW(executor.execute(), NotEnoughParameters);
}

TEST(Workflow4, Workflow){
    ofstream fout;
    fout.open("workflow.txt");
    fout << "desc\n";
    fout << "1 = readfile in.txt\n";
    fout << "2 = writefile out.txt\n";
    fout << "3 = sort\n";
    fout << "10 = replace workflow task\n";
    fout << "4 = grep task\n";
    fout << "7 = dump in.txt\n";
    fout << "8 = replace bozhko anna\n";
    fout << "csed\n";
    fout << "1 -> 7 -> 3 -> 10 -> 8 -> 2\n";
    fout.close();

    ofstream input;
    input.open("in.txt");
    input << "anna bozhko oop\n";
    input << "workflow task\n";
    input << "qwerty qwerty\n";
    input << "abcd";
    input.close();

    Executor executor("workflow.txt");
    try{
        executor.execute();
    }
    catch(UnknownBlock &error){
        error.printMessage();
    }
    catch(IncorrectConnection &error){
        error.printMessage();
    }
    catch(TooMuchParameters &error){
        error.printMessage();
    }
    catch(NotEnoughParameters &error){
        error.printMessage();
    }
    catch(ValidationError &error){
        error.printMessage();
    }
    catch(CommonError &error){
        error.printMessage();
    }

    fstream output;
    output.open("out.txt");
    string line;
    getline(output, line);
    EXPECT_EQ(line, "abcd");
    getline(output, line);
    EXPECT_EQ(line, "anna anna oop");
    getline(output, line);
    EXPECT_EQ(line, "qwerty qwerty");
    getline(output, line);
    EXPECT_EQ(line, "task task");
    output.close();
}
