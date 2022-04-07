#include <UnivSim/spatial/AABB.h>
#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>


// write Tests for every method of AABB
TEST(AABBTest, AABB_Constructor)
{
    Entity* entity = new Entity();
    AABB* aabb = new AABB(entity, 1.0f, 1.0f, 1.0f);
    EXPECT_EQ(entity, aabb->getEntity());
    EXPECT_EQ(1, aabb->getHalfWidthX());
    EXPECT_EQ(1, aabb->getHalfWidthY());
    EXPECT_EQ(1, aabb->getHalfWidthZ());
}

TEST(AABBTest, AABB_Contains)
{
    Entity* entity = new Entity();
    AABB* aabb = new AABB(entity, 1.0f, 1.0f, 1.0f);
    Entity* entity2 = new Entity();
    EXPECT_TRUE(aabb->contains(entity));
    EXPECT_FALSE(aabb->contains(entity2));
}

TEST(AABBTest, AABB_Intersects)
{
    Entity* entity = new Entity();
    AABB aabb(entity, 1.0f, 1.0f, 1.0f);

    Entity* entity2 = new Entity();
    entity2->setPosition(2.0f, 2.0f, 2.0f);
    AABB other(entity2, 0.25f, 0.25f, 0.25f);
    EXPECT_TRUE(aabb.intersects(other));
    EXPECT_FALSE(aabb.intersects(entity2));
}


