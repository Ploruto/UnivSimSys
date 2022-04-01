#include <UnivSim/spatial/Octree.h>

Octree::Octree(Bounds &bounds): m_bounds(bounds)
{
    m_numChildren = 0;
    m_children.resize(8);
    m_entityPoint = EntityPoint();
}

Octree::Octree(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax): m_bounds(xMin, yMin, zMin, xMax, yMax, zMax)
{
    m_numChildren = 0;
    m_children.resize(8);
    m_entityPoint = EntityPoint();
}

// compare the point to the middle of the octree's bounds
short Octree::getOctant(EntityPoint point, Bounds bounds)
{
    short octant = 0b00000;
    if(point.getX() < bounds.getXMid())
        octant |= 0b00001;
    if(point.getY() < bounds.getYMid())
        octant |= 0b00010;
    if(point.getZ() < bounds.getZMid())
        octant |= 0b00100;
    return octant;
}