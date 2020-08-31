#ifndef Point_h
#define Point_h;

class Point {
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
        const void print();
        // Returns distance from origin (0,0).
        const double distToOrig();
        // Returns distance to Point X.
        const double distTo(Point &X);
        // Sum this coordinates with coordinates of X.
        void sumOf(Point &X);
        // Returns new point witch is the sum of this and X.
        const Point sumOf(Point X);
};

#endif