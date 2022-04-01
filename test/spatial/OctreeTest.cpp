#include <gtest/gtest.h>
#include <UnivSim/spatial/Octree.h>

TEST(OctreeTest, OctreeConstructor) {
    EXPECT_EQ(Octree::getOctant(EntityPoint(1,1,1), Bounds(0,0,0,1,1,1)), 0);
    EXPECT_EQ(Octree::getOctant(EntityPoint(0,0,0), Bounds(0,0,0,1,1,1)), 7);
}