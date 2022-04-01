#include <UnivSim/spatial/EntityPoint.h>
#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>

TEST(EntityPointTest, EntityPoint123)
{
    EntityPoint point(nullptr, 1.0f, 2.0f, 3.0f);
    EXPECT_EQ(point.getX(), 1.0f);
    EXPECT_EQ(point.getY(), 2.0f);
    EXPECT_EQ(point.getZ(), 3.0f);
    EXPECT_EQ(point.getEntity(), nullptr);

    EntityPoint point2(nullptr, point);
    EXPECT_EQ(point2.getX(), 1.0f);
    EXPECT_EQ(point2.getY(), 2.0f);
    EXPECT_EQ(point2.getZ(), 3.0f);
    EXPECT_EQ(point2.getEntity(), nullptr);
}