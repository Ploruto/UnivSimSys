#include <UnivSim/spatial/Octree.h>

Octree::Octree(Bounds &bounds): m_bounds(bounds)
{
    m_parent = nullptr;
    m_numChildren = 0;
    m_children.resize(8);
    m_entityPoint = EntityPoint();
}

Octree::Octree(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax): m_bounds(xMin, yMin, zMin, xMax, yMax, zMax)
{
    m_parent = nullptr;
    m_numChildren = 0;
    m_children.resize(8);
    m_entityPoint = EntityPoint();
}

// Get the octant that the point belongs to.
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

// Get the bounds of an octant based on the bounds of the parent octree.
// The bounds of the octant will be one eighth of the parent bounds and will have a min or max at the center of the parent's center.
// The octant will be described by the bitmask.
Bounds Octree::getChildOctantBounds(short octant)
{
    float xMid = m_bounds.getXMid();
    float yMid = m_bounds.getYMid();
    float zMid = m_bounds.getZMid();
    float xMin = m_bounds.getXMin();
    float yMin = m_bounds.getYMin();
    float zMin = m_bounds.getZMin();
    float xMax = m_bounds.getXMax();
    float yMax = m_bounds.getYMax();
    float zMax = m_bounds.getZMax();
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
    Bounds bounds = getChildOctantBounds((short)octant);
    // insert a new octant in the right child octant
    m_children[octant] = new Octree(bounds);
    // set the octree's parent
    m_children[octant]->m_parent = this;
    // increment the number of children
    m_numChildren++;
}

void Octree::insert(EntityPoint point) {
    if(this->m_bounds.contains(point))
    {
        if(this->isEmpty())
        {
            if(this->m_entityPoint.getEntity() == nullptr)
            {
                // this octree is empty and has no entity point so we can add it and return
                this->m_entityPoint = point;
                return;
            }
            //find right octant for insertion
            short octant = getOctant(point, this->m_bounds);
            // we know that all children are empty, so we can fill the child octant
            this->fillChildOctant(octant);
            this->m_children[octant]->insert(point);

            // find right octant for insertion of the point that was previously stored in this octant
            short octantOldPoint = getOctant(this->m_entityPoint, this->m_bounds);
            // if both points belong into the same octant, we can just insert the point into the octant
            if(octantOldPoint == octant)
            {
                // start the recursive insertion for the new point
                this->m_children[octant]->insert(this->m_entityPoint);
                return;
            }
            // fill the octant that the old point belongs to
            this->fillChildOctant(octantOldPoint);
            // insert the old point into the octant
            this->m_children[octantOldPoint]->insert(this->m_entityPoint);
            // after inserting the old point, we set the m_entityPoint to nullptr
            this->m_entityPoint = EntityPoint();
            return;
        }

        // if the octree is not empty, we have to check to which child octant the point belongs to
        short octant = getOctant(point, this->m_bounds);
        // if the octant is empty, we can just insert the point
        if(this->m_children[octant] == nullptr)
        {
            fillChildOctant(octant);
            this->m_children[octant]->m_entityPoint = point;
            return;
        }
        // now we know the octant exists, so we can insert the point into the octant
        this->m_children[octant]->insert(point);

        // if the octant was empty the logic from above would take over, so we can return
        return;
    }
}
