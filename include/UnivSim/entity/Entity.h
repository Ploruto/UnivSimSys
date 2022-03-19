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
        Entity();
        Entity(UssVector &position);
        void receive_event();
        void set_perception_vector(UssVector perceptionVector);
        void set_movement_vector(UssVector movementVector);
        void set_position(UssVector position);
        UssVector get_perception_vector();
        UssVector get_movement_vector();
        UssVector get_position();

    private:
        void internal_example();

};
}


#endif
