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
    SpatialCell();
    
    long int getIndex(float x, float y);

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    void setIndex(long int index);
    void removeAllEntities();
    std::vector<Entity*> getEntities();
    std::vector<Entity*> getEntitiesInRadius(Entity* entity, float radius);
    long int getIndex();

    

};



#endif