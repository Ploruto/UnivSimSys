
#include <iostream>
#include <UnivSim/utils/math/UssVector.h>
#include <UnivSim/spatial/SpatialGrid.h>
#include <UnivSim/utils/math/UssVector.h>
#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>

class TestEntity : public Entity {
public:
    TestEntity(UssVector &v) : Entity{v} {}
    

    void test() {
        std::cout << "TestEntity::test()" << std::endl;
    }
    
};



int main(int argc, char* argv[]){

    //testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();


    SpatialGrid grid(10);
    UssVector v1(0,0,0);
    TestEntity testEntity(v1);
    Entity entity(v1);

    grid.addEntity(&testEntity);
    grid.addEntity(&entity);

    for (Entity* e : grid.getCellAtIndex(0L).getEntities()) {
        e->receive_event();
    }


}
