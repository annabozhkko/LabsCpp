#include "execute.h"
#include "exeption.h"

using namespace std;

int main(int argc, char **argv){
    if(argc != 2)
        return 0;

    Executor executor(argv[1]);
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

    return 0;
}
