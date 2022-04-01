#ifndef USimS_spatialPoint
#define USimS_spatialPoint

struct Point
{
private:
    float x,y,z;
public:
    Point(float x, float y, float z) : x(x), y(y), z(z) {}
    Point() : x(-1), y(-1), z(-1) {}

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float x);
    void setY(float y);
    void setZ(float z);
};


#endif