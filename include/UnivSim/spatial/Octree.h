#ifndef USimS_spatialOctree
#define USimS_spatialOctree

#include <UnivSim/spatial/EntityPoint.h>
#include <UnivSim/spatial/AABB.h>
#include <UnivSim/spatial/Bounds.h>


#include <vector>

/*
    assuming that x is "left/right" and y is "up/down" and z is "in/out"
    the octants will be described as follows:
    depending on where on every axis the point is, it will get a bitmask
    of the form:
    x: 0b00001 //means that the point is in the left half of the x-axis
    y: 0b00010 //means that the point is in the upper half of the y-axis
    z: 0b00100 //means that the point is in the inner half of the z-axis
    the bitmask will be used to determine which octant the point belongs to
    and then the point will be added to that octant
*/

struct Octree
{
    std::vector<Octree*> m_children;
    short m_numChildren;

    Bounds m_bounds;

    EntityPoint m_entityPoint;

    inline bool isFull() { return numChildren == 8; }
    inline bool isEmpty() { return numChildren == 0; }

    Octree(Bounds bounds);
    Octree(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax);

    void insert(EntityPoint point);
    void insert(EntityPoint* points, int numPoints);
    void insert(std::vector<EntityPoint> points);
    
    static short getOctant(EntityPoint point, Bounds bounds);
    
}




#endif