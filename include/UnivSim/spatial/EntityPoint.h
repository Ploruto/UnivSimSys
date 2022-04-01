#ifndef USimS_spatialEntityPoint
#define USimS_spatialEntityPoint
#include <UnivSim/utils/math/UssVector.h>
#include <UnivSim/entity/Entity.h>

struct EntityPoint : public UssVector
{
private:
    Entity* m_entity;
public:
    EntityPoint(Entity* entity, float x, float y, float z);
    EntityPoint(Entity* entity, UssVector &v);
    EntityPoint(Entity* entity);
    EntityPoint(float x, float y, float z); // use nullptr for entity
    EntityPoint(UssVector &v); // use nullptr for entity

    Entity* getEntity();
};

#endif