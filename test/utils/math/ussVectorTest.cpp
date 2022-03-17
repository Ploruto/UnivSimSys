#include <gtest/gtest.h>
#include <UnivSim/utils/math/ussVector.h>

TEST(ussVectorTest, ussVectorOperations){
    ussVector v1(10,10,10);
    ussVector v2(20,20,20);

    ussVector vR = v1 + v2;
    EXPECT_EQ(vR, ussVector(30,30,30));

    vR = v1 - v2;
    EXPECT_EQ(vR, ussVector(-10,-10,-10));

}

