#ifndef USimS_entity
#define USimS_entity

#include <UnivSim/utils/math/UssVector.h>

namespace entity {
class Entity{
    private:
        UssVector m_perceptionVector;
        UssVector m_movementVector;
        UssVector m_position;


    public:
        void receive_event();


    private:
        void internal_example();


};
}


#endif
