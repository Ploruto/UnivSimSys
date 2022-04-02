#ifndef USimS_spatialAABB
#define USimS_spatialAABB
#include <UnivSim/entity/Entity.h>
#include <UnivSim/utils/math/UssVector.h>

class Entity;

struct AABB
{
private:
    Entity* m_entity;
    float m_halfWidth;

public:
    AABB(Entity* center, float halfWidth);
    bool contains(Entity* p) const;
    bool intersects(AABB other) const;
    bool intersects(Entity* p);

    Entity* getEntity() const;

    UssVector getCenter() const;
    float getHalfWidth() const;
};



#endif