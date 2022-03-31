#ifndef USimS_spatialGrid
#define USimS_spatialGrid
#include <UnivSim/entity/Entity.h>
#include <UnivSim/spatial/SpatialCell.h>
#include <vector>

struct SpatialGrid
{
    private:
        float m_cellSize;
        float minCoord, maxCoord;
        int m_numberOfCellsPerAxis;
        std::vector<SpatialCell> m_cells;

    public:
        SpatialGrid(int numberOfCellsPerAxis);
        SpatialGrid(int numberOfCellsPerAxis, float minCoord, float maxCoord);

        bool isInGrid(float x, float y);

        void addEntity(Entity* entity);

        void removeEntity(Entity* entity);
        void removeAllEntities();

        std::vector<Entity*> getEntitiesInRadius(Entity* entity, float radius);
        std::vector<Entity*> getEntitiesInRadius(float x, float y, float radius);

        SpatialCell getCellAtIndex(long int index);
        SpatialCell getCellAtCoord(float x, float y);

        long int getIndexAtCoord(float x, float y);




};


#endif