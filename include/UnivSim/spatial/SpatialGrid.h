#ifndef USimS_spatialGrid
#define USimS_spatialGrid
#include <UnivSim/entity/entity.h>
#include <vector>

struct SpatialGrid
{
    private:
        std::vector<entity::Entity*> m_entities;

};


#endif