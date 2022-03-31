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
        float x, y, z;
    public:
    UssVector(float x, float y, float z);
    UssVector();

    void setVector(float x, float y, float z);
    void setX(float x);
    void setY(float y);
    void setZ(float z);

    float getX() const;
    float getY() const;
    float getZ() const;

    static UssVector getBasisVector(DIRECTION direction);

    UssVector toUnitVector() const;

    UssVector operator+(const UssVector &v2) const;
    UssVector operator-(const UssVector &v2) const;
    UssVector operator*(const UssVector &v2) const;
    UssVector operator*(float scalar) const;
    UssVector operator/(const UssVector &v2) const;
    UssVector operator/(float scalar) const;
    UssVector operator=(const UssVector &v2);
    bool operator== (const UssVector &v2) const;

    float getCrossProduct(const UssVector &v2) const;
    float getDotProduct(const UssVector &v2) const;

    bool isEqual(const UssVector &v2) const;
    float getMagnitute() const;
    bool isEqualDirection(const UssVector &v2) const;
    float getDistance(const UssVector &v2) const;

    static float getDistance(const UssVector &v1, const UssVector &v2);

};

#endif
