#ifndef USimS_spatialBounds
#define USimS_spatialBounds
#include <UnivSim/entity/Entity.h>
#include <UnivSim/utils/math/UssVector.h>


struct Bounds
{
    float xMin, yMin, zMin, xMax, yMax, zMax;
    Bounds(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax);
    Bounds(UssVector min, UssVector max);
    Bounds(Entity* min, Entity* max);

    bool contains(Entity* point);
    bool contains(UssVector &point);
    inline float getXMid() { return (xMin + xMax) / 2; }
    inline float getYMid() { return (yMin + yMax) / 2; }
    inline float getZMid() { return (zMin + zMax) / 2; }
    inline float getXMin() { return xMin; }
    inline float getYMin() { return yMin; }
    inline float getZMin() { return zMin; }
    inline float getXMax() { return xMax; }
    inline float getYMax() { return yMax; }
    inline float getZMax() { return zMax; }
    
};


#endif