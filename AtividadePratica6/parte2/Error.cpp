#include "Error.h"
#include <iostream>

using std::cout;
using std::endl;

Error::Error(){
    this->message = "Algo deu errado!";
}

Error::Error(const string X){
    this->message = X;
}

void Error::print() const {
    cout << this->message << endl;
}