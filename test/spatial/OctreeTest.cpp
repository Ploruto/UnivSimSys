#include <gtest/gtest.h>
#include <iostream>
#include <UnivSim/spatial/Octree.h>
#include <UnivSim/spatial/Bounds.h>
#include <UnivSim/entity/Entity.h>




TEST(OctreeTest, octreeTestsGetParent)
{
    Bounds bounds(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    Octree* octree = new Octree(bounds);
    EXPECT_EQ(octree->m_parent, nullptr);
}

// check if insertion of entities works
TEST(OctreeTest, octreeTestsInsertion)
{

    Bounds bounds(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    Octree* octree = new Octree(bounds);
    Entity* entity = new Entity();

    EXPECT_TRUE(octree->m_entity == nullptr);

    entity->setPosition(0.5f, 0.5f, 0.5f);
    // inserting should lead to the octree being empty but holding the entity
    octree->insert(entity);
    EXPECT_FALSE(octree->m_entity == nullptr);

    // create a second entity and insert it
    Entity* entity2 = new Entity();
    entity2->setPosition(0.5f, 0.5, 0.5);

    EXPECT_FALSE(octree->insert(entity2)); //inserting this shouldn't work!!! because there is a point with the same position


}

