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
    cout << "[" << id << "] -"
         << " (" << Xcord << "," << Ycord << ")" << endl;
};

double Point::distToOrig() const
{
    return sqrt(exp2(Xcord) + exp2(Ycord));
};

double Point::distTo(Point &A) const
{
    return sqrt(exp2(Xcord - A.Xcord) + exp2(Ycord - A.Ycord));
};

void Point::sumOf(Point *A)
{
    this->Xcord += A->Xcord;
    this->Ycord += A->Ycord;
};

Point Point::sumOf(Point A) const
{
    Point result(Xcord + A.Xcord, Ycord + A.Ycord);
    return result;
};