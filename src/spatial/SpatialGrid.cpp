#include <UnivSim/spatial/SpatialGrid.h>
#include <UnivSim/entity/Entity.h>
#include <UnivSim/spatial/SpatialCell.h>
#include <UnivSim/utils/math/UssVector.h>
#include <vector>
#include <limits>

// Constructor
SpatialGrid::SpatialGrid(int numberOfCells) : m_numberOfCellsPerAxis(numberOfCells) {
    double maxDouble{std::numeric_limits<double>::max()};
    this->m_cells = std::vector<SpatialCell>(numberOfCells * numberOfCells);
    this->m_cellSize = (maxDouble / numberOfCells * 2) - 2;
    this->minCoord = -maxDouble + 1;
    this->maxCoord = maxDouble;
    long int index{0};
    for(auto &cell : this->m_cells) {
        cell.setIndex(index++);
    }
}
// Constructor
SpatialGrid::SpatialGrid(int numberOfCells, double minCoord, double maxCoord) : m_numberOfCellsPerAxis(numberOfCells), minCoord(minCoord), maxCoord(maxCoord) {
    this->m_cells = std::vector<SpatialCell>(numberOfCells * numberOfCells);
    this->m_cellSize = (maxCoord - minCoord) / numberOfCells;
    long int index{0};
    for(auto &cell : this->m_cells) {
        cell.setIndex(index++);
    }
}

SpatialCell SpatialGrid::getCellAtIndex(long int index) {
    return this->m_cells.at(index);
}


long int SpatialGrid::getIndexAtCoord(double x, double y) {
    long int index = 0;
    index = (long int) ((x - this->minCoord) / this->m_cellSize) + (long int) ((y - this->minCoord) / this->m_cellSize) * this->m_numberOfCellsPerAxis;
    return index;
}


bool SpatialGrid::isInGrid(double x, double y) {
    return x >= this->minCoord && x <= this->maxCoord && y >= this->minCoord && y <= this->maxCoord;
}

void SpatialGrid::addEntity(Entity* entity) {
    long int index = this->getIndexAtCoord(entity->getPosition().getX(), entity->getPosition().getY());
    this->m_cells.at(index).addEntity(entity);
}

void SpatialGrid::removeEntity(Entity* entity) {
    long int index = this->getIndexAtCoord(entity->getPosition().getX(), entity->getPosition().getY());
    this->m_cells.at(index).removeEntity(entity);
}

SpatialCell SpatialGrid::getCellAtCoord(double x, double y) {
    long int index = this->getIndexAtCoord(x, y);
    return this->m_cells.at(index);
}

void SpatialGrid::removeAllEntities() {
    for (SpatialCell& cell : this->m_cells) {
        cell.removeAllEntities();
    }
}
//TODO: Implement this
std::vector<Entity*> SpatialGrid::getEntitiesInRadius(Entity* entity, double radius) {
    
}
//TODO: Implement this properly
std::vector<Entity*> SpatialGrid::getEntitiesInRadius(double x, double y, double radius) {
    std::vector<Entity*> result;
    long int index = this->getIndexAtCoord(x, y);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            long int indexNeighbour = index + i + j * this->m_numberOfCellsPerAxis;
            if (indexNeighbour >= 0 && indexNeighbour < this->m_cells.size()) {
                result.insert(result.end(), this->m_cells.at(indexNeighbour).getEntities().begin(), this->m_cells.at(indexNeighbour).getEntities().end());
            }
        }
    }
    return result;
}



