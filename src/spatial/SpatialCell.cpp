#include <UnivSim/spatial/SpatialCell.h>
#include <UnivSim/entity/Entity.h>
#include <UnivSim/utils/math/UssVector.h>
#include <vector>
#include <algorithm>

SpatialCell::SpatialCell(long int index) : m_index(index) {}
SpatialCell::SpatialCell() : m_index(-1) {}


void SpatialCell::addEntity(Entity* entity) {
    m_entities.push_back(entity);
}

void SpatialCell::removeEntity(Entity* entity){
    m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), entity), m_entities.end());
}

void SpatialCell::removeAllEntities() {
    m_entities.clear();
}

std::vector<Entity*> SpatialCell::getEntities() {
    return m_entities;
}

void SpatialCell::setIndex(long int index) {
    this->m_index = index;
}

long int SpatialCell::getIndex() {
    return m_index;
}

std::vector<Entity*> SpatialCell::getEntitiesInRadius(Entity* entity, double radius) {
    std::vector<Entity*> entitiesInRadius;
    for (Entity* e : m_entities) {
        if (entity != e) {
            double distance = UssVector::getDistance(entity->getPosition(), e->getPosition());
            if (distance <= radius) {
                entitiesInRadius.push_back(e);
            }
        }
    }
    return entitiesInRadius;
}

