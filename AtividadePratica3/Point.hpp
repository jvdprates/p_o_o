#ifndef Point_hpp
#define Point_hpp

class Point
{
private:
    // Saves X coordinate.
    double cordX;
    // Saves Y coordinate.
    double cordY;
    // Unique id to Point.
    const int id;

public:
    // Constructor of point, creates new point of (X,Y) with unique id.
    Point(double X = 0, double Y = 0);
    // Destructor of point.
    ~Point();
    // Prints Point on console.
    void print() const;
    // Returns distance from origin (0,0).
    double distToOrig() const;
    // Returns distance to Point X.
    double distTo(Point &X) const;
    // Sum this coordinates with coordinates of X.
    void sumOf(Point &X);
    // Returns new point witch is the sum of this and X.
    Point sumOf(Point X) const;
};

#endif