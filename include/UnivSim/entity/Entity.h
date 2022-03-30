#ifndef USimS_entity
#define USimS_entity

#include <UnivSim/utils/math/UssVector.h>

class Entity{
    private:
        UssVector m_perceptionVector;
        UssVector m_movementVector;
        UssVector m_position;

    public:
        Entity();
        Entity(UssVector &position);

        void receive_event();
        void setPerceptionVector(UssVector &perceptionVector);
        void setMovementVector(UssVector &movementVector);
        void setPosition(UssVector &position);
        UssVector getPerceptionVector() const;
        UssVector getMovementVector() const;
        UssVector getPosition() const;

    private:
        void internal_example();

};


#endif
