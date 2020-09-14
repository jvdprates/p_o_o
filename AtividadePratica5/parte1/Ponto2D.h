#ifndef Point2D_hpp
#define Point2D_hpp

class Ponto2D
{
    //X and Y coordinates of 2D point.
    int x, y;

public:
    //Constructs point with coordinates (xx,yy)
    Ponto2D(int xx = 0, int yy = 0) : x(xx), y(yy){};
    //Copy constructor
    Ponto2D(const Ponto2D &);
    //Assignment operator
    void operator=(const Ponto2D &);
    //Subtracts 1 from x and y coodinates
    Ponto2D operator--();
    //Returns the sums of coordinates of current point with &
    Ponto2D& operator+(const Ponto2D &);
    //Prints point
    void print();
    //Default destructor of point
    ~Ponto2D();
};

#endif