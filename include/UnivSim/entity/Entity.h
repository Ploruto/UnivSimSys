#ifndef USimS_entity
#define USimS_entity

#include <UnivSim/utils/math/UssVector.h>
#include <UnivSim/event/Event.h>

class Event;

class Entity{
    private:
        UssVector m_perceptionVector;
        UssVector m_movementVector;
        UssVector m_position;

    public:
        Entity();
        Entity(UssVector &position);

        virtual void receive_event(Event &e); //accept any event drived from Event class
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
