#ifndef USimS_entity
#define USimS_entity

#include <UnivSim/utils/math/UssVector.h>
#include <UnivSim/spatial/AABB.h>

class AABB;

class Entity {
private:
    UssVector m_perceptionVector;
    UssVector m_movementVector;
    UssVector m_position;
    long long m_uuid;
    AABB* m_aabb;

public:
    Entity();
    Entity(AABB* aabb);
    Entity(UssVector &position, UssVector &perceptionVector, UssVector &movementVector);
    static long long getNextUUID();

    void setPerceptionVector(UssVector &perceptionVector);
    void setMovementVector(UssVector &movementVector);
    void setPosition(UssVector &position);
    void setPosition(float x, float y, float z);
    UssVector getPerceptionVector() const;
    UssVector getMovementVector() const;
    UssVector getPosition() const;

    AABB* getAABB() const;
    void setAABB(AABB* aabb);

private:
    void internal_example();

};


#endif
