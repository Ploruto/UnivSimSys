#include <UnivSim/spatial/AABB.h>
#include <UnivSim/entity/Entity.h>


AABB::AABB(Entity* entity, float xHalfWidth, float yHalfWidth, float zHalfWidth): m_entity(entity),
 m_xHalfWidth(xHalfWidth), m_yHalfWidth(yHalfWidth), m_zHalfWidth(zHalfWidth) {}

UssVector AABB::getCenter() const {
    return m_entity->getPosition();
}

Entity* AABB::getEntity() const {
    return m_entity;
}

void AABB::setHalfWidth(float x, float y, float z) {
    m_xHalfWidth = x;
    m_yHalfWidth = y;
    m_zHalfWidth = z;
}

float AABB::getHalfWidthX() const {
    return m_xHalfWidth;
}

float AABB::getHalfWidthY() const {
    return m_yHalfWidth;
}

float AABB::getHalfWidthZ() const {
    return m_zHalfWidth;
}


bool AABB::contains(Entity* p) const
{
    return (p->getPosition().getX() >= this->getCenter().getX() - m_xHalfWidth && p->getPosition().getX() <= this->getCenter().getX() + m_xHalfWidth &&
            p->getPosition().getY() >= this->getCenter().getY() - m_yHalfWidth && p->getPosition().getY() <= this->getCenter().getY() + m_yHalfWidth &&
            p->getPosition().getZ() >= this->getCenter().getZ() - m_zHalfWidth && p->getPosition().getZ() <= this->getCenter().getZ() + m_zHalfWidth);
}

bool AABB::intersects(AABB &other) const
{
    return (this->getCenter().getX() - m_xHalfWidth <= other.getCenter().getX() + other.getHalfWidthX() &&
            this->getCenter().getX() + m_xHalfWidth >= other.getCenter().getX() - other.getHalfWidthX() &&
            this->getCenter().getY() - m_yHalfWidth <= other.getCenter().getY() + other.getHalfWidthY() &&
            this->getCenter().getY() + m_yHalfWidth >= other.getCenter().getY() - other.getHalfWidthY() &&
            this->getCenter().getZ() - m_zHalfWidth <= other.getCenter().getZ() + other.getHalfWidthZ() &&
            this->getCenter().getZ() + m_zHalfWidth >= other.getCenter().getZ() - other.getHalfWidthZ());
}

