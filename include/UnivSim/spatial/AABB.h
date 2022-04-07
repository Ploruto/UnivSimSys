#ifndef USimS_spatialAABB
#define USimS_spatialAABB
#include <UnivSim/entity/Entity.h>
#include <UnivSim/utils/math/UssVector.h>

class Entity;

struct AABB
{
private:
    Entity* m_entity;
    float m_xHalfWidth;
    float m_yHalfWidth;
    float m_zHalfWidth;

public:
    AABB(Entity* center, float xHalfWidth, float yHalfWidth, float zHalfWidth);
    bool contains(Entity* p) const;
    bool intersects(AABB &other) const;
    bool intersects(Entity* p) const;

    Entity* getEntity() const;

    UssVector getCenter() const;
    float getHalfWidthX() const;
    float getHalfWidthY() const;
    float getHalfWidthZ() const;
    void setHalfWidth(float x, float y, float z);
};



#endif