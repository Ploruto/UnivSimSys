#ifndef USimS_vector
#define USimS_vector
#include <math.h>

struct UssVector {

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
    UssVector(double x, double y, double z);

    void setVector(double x, double y, double z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    static UssVector getBasisVector(DIRECTION direction);

    UssVector toUnitVector() const;

    UssVector operator+(const UssVector &v2) const;
    UssVector operator-(const UssVector &v2) const;
    UssVector operator*(const UssVector &v2) const;
    UssVector operator*(double scalar) const;
    UssVector operator/(const UssVector &v2) const;
    UssVector operator/(double scalar) const;
    UssVector operator=(const UssVector &v2);
    bool operator== (const UssVector &v2) const;

    double getCrossProduct(const UssVector &v2) const;
    double getDotProduct(const UssVector &v2) const;

    bool isEqual(const UssVector &v2) const;
    double getMagnitute() const;
    bool isEqualDirection(const UssVector &v2) const;

};

#endif
