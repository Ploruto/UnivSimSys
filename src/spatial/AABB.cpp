#include <UnivSim/spatial/AABB.h>
#include <UnivSim/entity/Entity.h>


AABB::AABB(Entity* entity, float halfWidth): m_entity(entity), m_halfWidth(halfWidth) {}

UssVector AABB::getCenter() const {
    return m_entity->getPosition();
}

Entity* AABB::getEntity() const {
    return m_entity;
}

float AABB::getHalfWidth() const {
    return m_halfWidth;
}

bool AABB::contains(Entity* p) const
{
    return (p->getPosition().getX() >= this->getCenter().getX() - m_halfWidth && p->getPosition().getX() <= this->getCenter().getX() + m_halfWidth &&
            p->getPosition().getY() >= this->getCenter().getY() - m_halfWidth && p->getPosition().getY() <= this->getCenter().getY() + m_halfWidth &&
            p->getPosition().getZ() >= this->getCenter().getZ() - m_halfWidth && p->getPosition().getZ() <= this->getCenter().getZ() + m_halfWidth);
}

bool AABB::intersects(AABB other) const
{
    return (this->getCenter().getX() - m_halfWidth <= other.getCenter().getX() + other.getHalfWidth() &&
            this->getCenter().getX() + m_halfWidth >= other.getCenter().getX() - other.getHalfWidth() &&
            this->getCenter().getY() - m_halfWidth <= other.getCenter().getY() + other.getHalfWidth() &&
            this->getCenter().getY() + m_halfWidth >= other.getCenter().getY() - other.getHalfWidth() &&
            this->getCenter().getZ() - m_halfWidth <= other.getCenter().getZ() + other.getHalfWidth() &&
            this->getCenter().getZ() + m_halfWidth >= other.getCenter().getZ() - other.getHalfWidth());
}

