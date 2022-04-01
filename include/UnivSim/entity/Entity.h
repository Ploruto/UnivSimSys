#ifndef USimS_entity
#define USimS_entity

#include <UnivSim/utils/math/UssVector.h>

class Entity {
private:
    UssVector m_perceptionVector;
    UssVector m_movementVector;
    UssVector m_position;
    long long m_uuid;

public:
    Entity();
    Entity(UssVector &position, UssVector &perceptionVector, UssVector &movementVector);
    static long long getNextUUID();

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
