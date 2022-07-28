#include <string>
#include <iostream>

using namespace std;

class CommonError{
public:
    CommonError(string ms) {message = ms;}
    void printMessage(){
        cout << message;
    }
private:
    string message;
};

class ValidationError: public CommonError{
public:
    ValidationError(string ms): CommonError(ms){}
};

class NotEnoughParameters: public ValidationError{
public:
    NotEnoughParameters(string ms): ValidationError(ms){}
};

class TooMuchParameters: public ValidationError{
public:
    TooMuchParameters(string ms): ValidationError(ms){}
};

class IncorrectConnection: public ValidationError{
public:
    IncorrectConnection(string ms): ValidationError(ms){}
};

class UnknownBlock: public ValidationError{
public:
    UnknownBlock(string ms): ValidationError(ms){}
};
