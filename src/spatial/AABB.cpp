#include <UnivSim/spatial/AABB.h>
#include <UnivSim/spatial/EntityPoint.h>


AABB::AABB(EntityPoint center, float halfWidth): m_center(center), m_halfWidth(halfWidth) {}

EntityPoint AABB::getCenter() const {
    return m_center;
}

float AABB::getHalfWidth() const {
    return m_halfWidth;
}

bool AABB::contains(EntityPoint p) const
{
    return (p.getX() >= m_center.getX() - m_halfWidth && p.getX() <= m_center.getX() + m_halfWidth &&
            p.getY() >= m_center.getY() - m_halfWidth && p.getY() <= m_center.getY() + m_halfWidth &&
            p.getZ() >= m_center.getZ() - m_halfWidth && p.getZ() <= m_center.getZ() + m_halfWidth);
}

bool AABB::intersects(AABB other) const
{
    return (m_center.getX() - m_halfWidth <= other.getCenter().getX() + other.getHalfWidth() &&
            m_center.getX() + m_halfWidth >= other.getCenter().getX() - other.getHalfWidth() &&
            m_center.getY() - m_halfWidth <= other.getCenter().getY() + other.getHalfWidth() &&
            m_center.getY() + m_halfWidth >= other.getCenter().getY() - other.getHalfWidth() &&
            m_center.getZ() - m_halfWidth <= other.getCenter().getZ() + other.getHalfWidth() &&
            m_center.getZ() + m_halfWidth >= other.getCenter().getZ() - other.getHalfWidth());
}

