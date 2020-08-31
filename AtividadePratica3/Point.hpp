#ifndef Point_hpp
#define Point_hpp

class Point
{
private:
    // Saves X coordinate.
    double Xcord;
    // Saves Y coordinate.
    double Ycord;
    // Unique id to Point.
    const int id;
    
public:
    // Constructor of Point, creates new point of (X,Y) with unique id.
    Point(double X = 0, double Y = 0);
    // Returns index of Point.
    int getIndex() const;
    // Sets new coordinates for a point.
    void setCord(double X, double Y);
    // Prints Point on console.
    void print() const;
    // Returns distance from origin (0,0).
    double distToOrig() const;
    // Returns distance to Point A.
    double distTo(Point &A) const;
    // Sum this coordinates with coordinates of A.
    void sumOf(Point* A);
    // Returns new point witch is the sum of this and A.
    Point sumOf(Point A) const;
};

#endif