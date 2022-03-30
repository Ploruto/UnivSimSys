
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




}
