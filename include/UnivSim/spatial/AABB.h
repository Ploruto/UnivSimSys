#ifndef USimS_spatialAABB
#define USimS_spatialAABB
#include <UnivSim/spatial/Point.h>

struct AABB
{
private:
    Point center;
    float halfWidth;
public:
    AABB(Point center, float halfWidth) : center(center), halfWidth(halfWidth) {}
    bool contains(Point p) const;
    bool intersects(AABB other) const;
};



#endif