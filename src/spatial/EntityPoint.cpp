#include <UnivSim/spatial/EntityPoint.h>
#include <UnivSim/entity/Entity.h>

EntityPoint::EntityPoint(Entity* entity, float x, float y, float z) : UssVector(x, y, z)
{
    m_entity = entity;
}

EntityPoint::EntityPoint(Entity* entity, const UssVector &point) : UssVector(point)
{
    m_entity = entity;
}

EntityPoint::EntityPoint(float x, float y, float z) : UssVector(x, y, z)
{
    m_entity = nullptr;
}

EntityPoint::EntityPoint(const UssVector &point) : UssVector(point)
{
    m_entity = nullptr;
}

EntityPoint::EntityPoint() : UssVector()
{
    m_entity = nullptr;
}

EntityPoint::EntityPoint(Entity* entity) : UssVector()
{
    m_entity = entity;
}

Entity* EntityPoint::getEntity()
{
    return m_entity;
}
