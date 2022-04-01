#ifndef USimS_spatialBounds
#define USimS_spatialBounds
#include <UnivSim/spatial/EntityPoint.h>


struct Bounds
{
    float xMin, yMin, zMin, xMax, yMax, zMax;
    Bounds(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax);
    Bounds(EntityPoint min, EntityPoint max);

    bool contains(EntityPoint point);
    inline float getXMid() { return (xMin + xMax) / 2; }
    inline float getYMid() { return (yMin + yMax) / 2; }
    inline float getZMid() { return (zMin + zMax) / 2; }
    
};


#endif