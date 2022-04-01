#include <gtest/gtest.h>
#include <UnivSim/spatial/Octree.h>
#include <UnivSim/spatial/Bounds.h>
#include <UnivSim/spatial/EntityPoint.h>

TEST(OctreeTest, OctreeConstructor) {
    EXPECT_EQ(Octree::getOctant(EntityPoint(1,1,1), Bounds(0,0,0,1,1,1)), 0);
    EXPECT_EQ(Octree::getOctant(EntityPoint(0,0,0), Bounds(0,0,0,1,1,1)), 7);

    Bounds b(0,0,0,100,100,100);
    Octree o(b);

    Entity* e = new Entity();
    EntityPoint p(e);
    o.insert(p);

    // create new entity and EntityPoint and insert them into the octree
    Entity* e2 = new Entity();
    EntityPoint p2(e2);
    o.insert(p2);


    o.m_children.at(0)->m_entityPoint.getEntity();


}