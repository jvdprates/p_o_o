#include <iostream>
#include "Matrix.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;

int main(){
    ifstream myFile;
    Matrix a(myFile);
    return 0;
}