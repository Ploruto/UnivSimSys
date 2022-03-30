#ifndef USimS_spatialGrid
#define USimS_spatialGrid
#include <UnivSim/entity/Entity.h>
#include <UnivSim/spatial/SpatialCell.h>
#include <vector>

struct SpatialGrid
{
    private:
        double m_cellSize;
        double minCoord, maxCoord;
        int m_numberOfCellsPerAxis;
        std::vector<SpatialCell> m_cells;

    public:
        SpatialGrid(int numberOfCellsPerAxis);
        SpatialGrid(int numberOfCellsPerAxis, double minCoord, double maxCoord);

        bool isInGrid(double x, double y);

        void addEntity(Entity* entity);

        void removeEntity(Entity* entity);
        void removeAllEntities();

        std::vector<Entity*> getEntitiesInRadius(Entity* entity, double radius);
        std::vector<Entity*> getEntitiesInRadius(double x, double y, double radius);

        SpatialCell getCellAtIndex(long int index);
        SpatialCell getCellAtCoord(double x, double y);

        long int getIndexAtCoord(double x, double y);




};


#endif