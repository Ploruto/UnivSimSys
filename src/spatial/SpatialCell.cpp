#include <UnivSim/spatial/SpatialCell.h>
#include <UnivSim/entity/Entity.h>
#include <UnivSim/utils/math/UssVector.h>
#include <vector>

SpatialCell::SpatialCell(long int index) : m_index(index) {}


void SpatialCell::addEntity(Entity* entity) {
    m_entities.push_back(entity);
}

void SpatialCell::removeEntity(Entity* entity) {
    m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), entity), m_entities.end());
}

void SpatialCell::removeAllEntities() {
    m_entities.clear();
}

std::vector<Entity*> SpatialCell::getEntities() {
    return m_entities;
}

long int SpatialCell::getIndex() {
    return m_index;
}

Entity* SpatialCell::getEntitiesInRadius(Entity* entity, double radius) {
    Entity* result = nullptr;
    for (Entity* e : m_entities) {
        if (entity != e) {
            double distance = UssVector::getDistance(entity->getPosition(), e->getPosition());
            if (distance <= radius) {
                result = e;
            }
        }
    }
    return result;
}