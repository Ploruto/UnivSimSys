#ifndef USimS_spatialAABB
#define USimS_spatialAABB
#include <UnivSim/spatial/EntityPoint.h>

struct AABB
{
private:
    EntityPoint center;
    float halfWidth;
public:
    AABB(EntityPoint center, float halfWidth) : center(center), halfWidth(halfWidth) {}
    bool contains(EntityPoint p) const;
    bool intersects(AABB other) const;
};



#endif