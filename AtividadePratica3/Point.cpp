#include "./Point.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int currentId = 1;
int getNextId(){
    currentId++;
    return currentId;
}

Point::Point(double X, double Y): id(getNextId()){
    cordX = X;
    cordY = Y;
};

Point::~Point(){
    delete &cordX, &cordY, &id;
    delete [] this;
};

const void Point::print(){
    cout << "Ponto [" << id << "] " << "---" << "(" << cordX << "," << cordY << ")" << endl; 
};

const double Point::distToOrig(){
    return sqrt(exp2(cordX)+exp2(cordY));
};

const double Point::distTo(Point &X){
    return sqrt(exp2(cordX - X.cordX) + exp2(cordY - X.cordY));
};

void Point::sumOf(Point &X){
    cordX += X.cordX;
    cordY += X.cordY;
};

const Point Point::sumOf(Point X){
    Point result(cordX + X.cordX, cordY + X.cordY);
    return result;
};