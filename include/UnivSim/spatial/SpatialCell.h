#ifndef USimS_spatialCell
#define USimS_spatialCell
#include <UnivSim/entity/Entity.h>
#include <vector>

struct SpatialCell
{
    private:
        std::vector<Entity*> m_entities;
        long int m_index;

    public:
    SpatialCell(long int index);

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    void removeAllEntities();
    std::vector<Entity*> getEntities();
    Entity* getEntityAtIndex(long int index);
    long int getIndex();

    Entity* getEntitiesInRadius(Entity* entity, double radius);

};



#endif