#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <string>

using std::string;
using std::cout;

class Error {
    private:
        string message;
    public:
        Error();
        Error(const string);
        void print() const;
};

#endif