#include <gtest/gtest.h>
#include <UnivSim/utils/math/UssVector.h>

TEST(UssVectorTest, UssVectorOperations){
    UssVector v1(10,10,10);
    UssVector v2(20,20,20);

    UssVector vR = v1 + v2;
    EXPECT_EQ(vR, UssVector(30,30,30));

    vR = v1 - v2;
    EXPECT_EQ(vR, UssVector(-10,-10,-10));


}

