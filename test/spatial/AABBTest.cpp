#include <UnivSim/spatial/AABB.h>
#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>

TEST(AABBTestOperations, aabbTests)
{
    EntityPoint center(nullptr, 1.0f, 2.0f, 3.0f);
    AABB aabb(center, 0.2f);
    EXPECT_EQ(aabb.getCenter().getX(), 1.0f);
    EXPECT_EQ(aabb.getCenter().getY(), 2.0f);
    EXPECT_EQ(aabb.getCenter().getZ(), 3.0f);
    EXPECT_EQ(aabb.getCenter().getEntity(), nullptr);
    EXPECT_EQ(aabb.getHalfWidth(), 0.2f);

    EntityPoint center2(nullptr, 2.0f, 3.0f, 4.0f);
    AABB aabb3 = AABB(center2, 0.2f);
    
    EXPECT_EQ(aabb.intersects(aabb3), false);
    
}