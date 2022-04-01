#ifndef USimS_spatialBounds
#define USimS_spatialBounds
#include <UnivSim/spatial/EntityPoint.h>


struct Bounds
{
    float xMin, yMin, zMin, xMax, yMax, zMax;
    Bounds(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax);
    Bounds(EntityPoint min, EntityPoint max);

    bool contains(EntityPoint point);
    
};


#endif