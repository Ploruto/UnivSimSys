#ifndef USimS_spatialAABB
#define USimS_spatialAABB
#include <UnivSim/spatial/EntityPoint.h>

struct AABB
{
private:
    EntityPoint m_center;
    float m_halfWidth;

public:
    AABB(EntityPoint center, float halfWidth);
    bool contains(EntityPoint p) const;
    bool intersects(AABB other) const;

    EntityPoint getCenter() const;
    float getHalfWidth() const;
};



#endif