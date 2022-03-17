#ifndef USimS_vector
#define USimS_vector
#include <math.h>

struct ussVector {

    public:
    enum DIRECTION{
        RIGHT,
        LEFT,
        FORWARD,
        BACKWARD,
        DOWN,
        UP
    };    


    private:
        double x, y, z;
    public:
    ussVector(double x, double y, double z);

    void setVector(double x, double y, double z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    static ussVector getBasisVector(DIRECTION direction);

    ussVector toUnitVector();

    ussVector operator+(const ussVector &v2);
    ussVector operator-(const ussVector &v2);
    ussVector operator*(const ussVector &v2);
    ussVector operator*(double scalar);
    ussVector operator/(const ussVector &v2);
    ussVector operator/(double scalar);
    ussVector operator=(const ussVector &v2);
    bool operator==(const ussVector &v2);

    bool isEqual(const ussVector &v2);
    double getLength();
    bool isEqualDirection(const ussVector &v2);

};

#endif
