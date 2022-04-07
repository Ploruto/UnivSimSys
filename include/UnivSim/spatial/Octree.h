#ifndef USimS_spatialOctree
#define USimS_spatialOctree

#include <UnivSim/entity/Entity.h>
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
    Octree* m_parent;
    short m_numChildren;


    Bounds m_bounds;

    Entity* m_entity;

    inline bool isFull() {
        return this->m_numChildren == 8;
    }
    inline bool isEmpty() {
        return this->m_numChildren == 0;
    }
    inline bool isLeaf() {
        return this->m_numChildren == 0 && this->m_entity != nullptr;
    }
    inline bool holdsPoint() {
        return this->m_entity != nullptr;
    }

    Octree(Bounds &bounds);
    Octree(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax);

    // when insertion is not possible, because there already exists an entity with the same position, return false
    bool insert(Entity* point);
    bool insert(Entity* points, int numPoints);
    bool insert(std::vector<Entity *> points);

    bool find(Entity* point);


    static short getOctant(Entity* point, Bounds bounds);
    Bounds getChildOctantBounds(short octant);
    void fillChildOctant(short octant);




};




#endif