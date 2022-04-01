#include <gtest/gtest.h>
#include <iostream>
#include <UnivSim/spatial/Octree.h>
#include <UnivSim/spatial/Bounds.h>
#include <UnivSim/spatial/EntityPoint.h>

TEST(OctreeTest, OctreeOperations) {
    EXPECT_EQ(Octree::getOctant(EntityPoint(1,1,1), Bounds(0,0,0,1,1,1)), 7);
    EXPECT_EQ(Octree::getOctant(EntityPoint(0,0,0), Bounds(0,0,0,1,1,1)), 0);

    Bounds b(0,0,0,100,100,100);
    Octree o(b);

    Entity* e = new Entity();
    EntityPoint* p = new EntityPoint(e, 25.0f, 25.0f, 25.0f);
    o.insert(p);

    // create new entity and EntityPoint and insert them into the octree
    Entity* e2 = new Entity();
    EntityPoint* p2 = new EntityPoint(e2, 30.0f, 30.0f, 30.0f);
    o.insert(p2);

    // create new entity and EntityPoint and insert them into the octree
    Entity* e3 = new Entity();
    EntityPoint* p3 = new EntityPoint(e3, 70.0f, 70.0f, 70.0f);
    o.insert(p3);

    std::cout << o.find(p3) << std::endl;

    // create new entity and EntityPoint and insert them into the octree
    Entity* e4 = new Entity();
    EntityPoint* p4 = new EntityPoint(e4, 75.0f, 75.0f, 75.0f);
    o.insert(p4);

    // create new entity and entityPoint
    Entity* e5 = new Entity();
    EntityPoint* p5 = new EntityPoint(e5, 80.0f, 80.0f, 80.0f);
    std::cout << o.find(p5) << std::endl;


    EXPECT_EQ(o.find(p4), true);
    EXPECT_EQ(o.find(p5), false);

}