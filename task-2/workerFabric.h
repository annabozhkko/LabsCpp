#include "readfile.h"
#include "writefile.h"
#include "sort.h"
#include "grep.h"
#include "dump.h"
#include "replace.h"

#include <string>
#include <vector>

class WorkerFabric{
public:
    Worker* create(string blockTitle, vector<string> parameters);
};
