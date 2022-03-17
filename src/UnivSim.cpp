
#include <iostream>
#include <UnivSim/utils/math/ussVector.h>

int main(){

    std::cout << "It's working!" << std::endl;

    ussVector v = ussVector(10, 10, -20);
    
    ussVector v2 = ussVector(-5, 5, 5);

    ussVector v3 = v.toUnitVector(); 

std::cout << v3.getX() << std::endl;



}
