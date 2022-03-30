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

    SpatialGrid grid(20, 0, 100);
    UssVector uv1(10,10,10);
    UssVector uv2(11,11,11);
    UssVector uv3(12,12,12);

    Entity* entity = new Entity(uv1);
    grid.addEntity(entity);
    Entity* e2 = new Entity(uv2);
    Entity* e3 = new Entity(uv3);

    grid.addEntity(e2);
    grid.addEntity(e3);
    std::vector<Entity*> vE = grid.getEntitiesInRadius(entity, 3);

}