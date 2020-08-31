#include "Point.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int currentId = 0;
int getNextId()
{
    currentId++;
    return currentId;
};

Point::Point(double X, double Y) : id(getNextId())
{
    Xcord = X;
    Ycord = Y;
};

int Point::getIndex() const
{
    return id;
};

void Point::print() const
{
    cout << "[" << id << "] - (" << Xcord << "," << Ycord << ")" << endl;
};

double Point::distToOrig() const
{
    return sqrt(pow(Xcord, 2) + pow(Ycord, 2));
};

double Point::distTo(Point &A) const
{
    return sqrt(pow(Xcord - A.Xcord, 2) + pow(Ycord - A.Ycord, 2));
};

void Point::sumOf(Point *A)
{
    Xcord += A->Xcord;
    Ycord += A->Ycord;
};

Point Point::sumOf(Point A) const
{
    Point result(Xcord + A.Xcord, Ycord + A.Ycord);
    return result;
};