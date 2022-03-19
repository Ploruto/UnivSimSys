#ifndef USimS_spatialGrid
#define USimS_spatialGrid
#include <UnivSim/entity/entity.h>
#include <UnivSim/spatial/spatialCell.h>
#include <vector>

struct SpatialGrid
{
    private:
        const double m_cellSize;
        const double minCoord, maxCoord;
        const int m_numberOfCellsPerAxis;
        std::vector<SpatialCell> m_cells;

    public:
        SpatialGrid(int numberOfCellsPerAxis);
        SpatialGrid(int numberOfCellsPerAxis, double minCoord, double maxCoord);



};


#endif