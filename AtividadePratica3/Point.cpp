#include "./Point.hpp"
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
    cordX = X;
    cordY = Y;
};

int Point::getIndex() const
{
    return id;
};

void Point::print() const
{
    cout << "[" << id << "] -"
         << " (" << cordX << "," << cordY << ")" << endl;
};

double Point::distToOrig() const
{
    return sqrt(exp2(cordX) + exp2(cordY));
};

double Point::distTo(Point &X) const
{
    return sqrt(exp2(cordX - X.cordX) + exp2(cordY - X.cordY));
};

void Point::sumOf(Point* X)
{
    cordX += X->cordX;
    cordY += X->cordY;
};

Point Point::sumOf(Point X) const
{
    Point result(cordX + X.cordX, cordY + X.cordY);
    return result;
};