#include <gtest/gtest.h>
#include <UnivSim/spatial/SpatialCell.h>
#include <UnivSim/entity/Entity.h>
#include <iostream>

TEST(SpatialCellTest, SpatialCellOperations1){

    SpatialCell cell(1);
    Entity* entity = new Entity();
    cell.addEntity(entity);


    
    EXPECT_EQ(cell.getEntities().size(), 1);
    EXPECT_EQ(cell.getIndex(), 1);
}

TEST(SpatialCellTest, SpatialCellOperations2){

    SpatialCell cell(1);
    Entity* entity = new Entity();
    cell.addEntity(entity);
    cell.removeEntity(entity);

    EXPECT_EQ(cell.getEntities().size(), 0);
    EXPECT_EQ(cell.getIndex(), 1);
}

