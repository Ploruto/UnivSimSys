#include <UnivSim/spatial/SpatialGrid.h>
#include <UnivSim/spatial/SpatialCell.h>
#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>

TEST(SpatialGridTest, SpatialGridOperations1){
    SpatialGrid grid(20, 0, 100);
    SpatialCell sc = grid.getCellAtCoord(15,5);

    EXPECT_EQ(sc.getIndex(), 23);

}

TEST(SpatialGridTest, SpatialGridOperations2){

}