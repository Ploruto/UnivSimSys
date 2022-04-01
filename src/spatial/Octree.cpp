#include <UnivSim/spatial/Octree.h>
#include <iostream>
#include <queue>

Octree::Octree(Bounds &bounds): m_bounds(bounds)
{
    m_parent = nullptr;
    m_numChildren = 0;
    m_children.resize(8);
    m_entityPoint = new EntityPoint();
}

Octree::Octree(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax): m_bounds(xMin, yMin, zMin, xMax, yMax, zMax)
{
    m_parent = nullptr;
    m_numChildren = 0;
    m_children.resize(8);
    m_entityPoint = new EntityPoint();
}

// Get the octant that the point belongs to.
short Octree::getOctant(EntityPoint point, Bounds bounds)
{
    short octant = 0b00000;
    if(point.getX() > bounds.getXMid())
        octant |= 0b00001;
    if(point.getY() > bounds.getYMid())
        octant |= 0b00010;
    if(point.getZ() > bounds.getZMid())
        octant |= 0b00100;
    return octant;
}

// Get the bounds of an octant based on the bounds of the parent octree.
// The bounds of the octant will be one eighth of the parent bounds and will have a min or max at the center of the parent's center.
// The octant will be described by the bitmask.
Bounds Octree::getChildOctantBounds(short octant)
{
    float xMid = this->m_bounds.getXMid();
    float yMid = this->m_bounds.getYMid();
    float zMid = this->m_bounds.getZMid();
    float xMin = this->m_bounds.getXMin();
    float yMin = this->m_bounds.getYMin();
    float zMin = this->m_bounds.getZMin();
    float xMax = this->m_bounds.getXMax();
    float yMax = this->m_bounds.getYMax();
    float zMax = this->m_bounds.getZMax();
    switch(octant)
    {
    case 0b00000:
        return Bounds(xMin, yMin, zMin, xMid, yMid, zMid);
    case 0b00001:
        return Bounds(xMid, yMin, zMin, xMax, yMid, zMid);
    case 0b00010:
        return Bounds(xMin, yMid, zMin, xMid, yMax, zMid);
    case 0b00011:
        return Bounds(xMid, yMid, zMin, xMax, yMax, zMid);
    case 0b00100:
        return Bounds(xMin, yMin, zMid, xMid, yMid, zMax);
    case 0b00101:
        return Bounds(xMid, yMin, zMid, xMax, yMid, zMax);
    case 0b00110:
        return Bounds(xMin, yMid, zMid, xMid, yMax, zMax);
    case 0b00111:
        return Bounds(xMid, yMid, zMid, xMax, yMax, zMax);
    }
}

void Octree::fillChildOctant(short octant)
{
    // get the bounds of the new child octant
    Bounds bounds = getChildOctantBounds(octant);
    // insert a new octant in the right child octant
    this->m_children[octant] = new Octree(bounds);
    // set the octree's parent
    this->m_children[octant]->m_parent = this;
    // increment the number of children
    this->m_numChildren++;
}



// check whether the point is in the octree's bounds
// if it is, check if the current octree has children
// if it doesn't, set the octree's entity point to the point
// if it does, 
void Octree::insert(EntityPoint* point){
    static std::queue<EntityPoint *> queuedPoints;

    queuedPoints.push(point);
    while(!queuedPoints.empty())
    {
        EntityPoint* point = queuedPoints.front();
        queuedPoints.pop();
        if(this->m_bounds.contains(*point))
        {
            if(this->isEmpty() && this->holdsNoPoint())
            {
                std::cout << "inserting point" << std::endl;
                this->m_entityPoint = point;
            }
            else
            {
                short octant = getOctant(*point, this->m_bounds);
                if(this->m_children[octant] == nullptr)
                {
                    this->fillChildOctant(octant);
                    this->m_numChildren++;
                }
                // the goal is to make this land in the isEmpty && holdNoPoint branch
                this->m_children[octant]->insert(point);

                if(!this->holdsNoPoint())
                {
                    queuedPoints.push(this->m_entityPoint);
                    m_entityPoint = new EntityPoint();
                }
            }
        }
        else
        {
            std::cout << "point out of bounds" << std::endl;
        }
    }
}


bool Octree::find(EntityPoint* point)
{
    if(this->m_bounds.contains(*point))
    {
        if(this->isEmpty() && this->m_entityPoint == point)
        {
            return this->m_entityPoint;
        }
        else
        {
            short octant = getOctant(*point, this->m_bounds);
            if(this->m_children[octant] == nullptr)
            {
                return false;
            }
            else
            {
                return this->m_children[octant]->find(point);
            }
        }
    }
    return false;
}