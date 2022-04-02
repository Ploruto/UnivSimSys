#include <UnivSim/spatial/AABB.h>
#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>

TEST(AABBTestOperations, aabbTestsGetEntity)
{
    Entity* entity = new Entity();
    AABB* aabb = new AABB(entity, 1.0f);
    EXPECT_EQ(aabb->getEntity(), entity);
}
TEST(AABBTestOperations, aabbTestsGetHalfWidth)
{
    Entity* entity = new Entity();
    AABB* aabb = new AABB(entity, 1.0f);
    EXPECT_EQ(aabb->getHalfWidth(), 1.0f);
}
TEST(AABBTestOperations, aabbTestsGetCenter)
{
    Entity* entity = new Entity();
    AABB* aabb = new AABB(entity, 1.0f);
    EXPECT_EQ(aabb->getCenter(), UssVector());
}
TEST(AABBTestOperations, aabbTestsContains)
{
    Entity* entity = new Entity();
    AABB* aabb = new AABB(entity, 1.0f);
    EXPECT_EQ(aabb->contains(entity), true); // (0,0,0) is inside the AABB

    UssVector position(1.5f, 1.5f, 1.5f);
    Entity* entity2 = new Entity(position, position, position);
    EXPECT_EQ(aabb->contains(entity2), false); // should not be contained
}
TEST(AABBTestOperations, aabbTestsIntersects)
{
    // create entity at position (1,1,1)
    // create AABB with halfWidth 1


    Entity* entity = new Entity();
    entity->setPosition(UssVector(1.0f, 1.0f, 1.0f));
    AABB* aabb = new AABB(entity, 1.0f);

    //create second entity at position (2,2,2)
    //create second AABB with halfWidth 0.5

    Entity* entity2 = new Entity();
    entity2->setPosition(UssVector(2.0f, 2.0f, 2.0f));
    AABB* aabb2 = new AABB(entity2, 0.5f);

    EXPECT_EQ(aabb->intersects(*aabb2), true); // should intersect

}
