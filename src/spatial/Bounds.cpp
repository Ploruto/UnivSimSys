#include <UnivSim/spatial/Bounds.h>
#include <UnivSim/entity/Entity.h>
#include <UnivSim/utils/math/UssVector.h>
#include <algorithm>


Bounds::Bounds(float xMin, float yMin, float zMin, float xMax, float yMax, float zMax) {
    if (xMin > xMax) {
        std::swap(xMin, xMax);
    }
    if (yMin > yMax) {
        std::swap(yMin, yMax);
    }
    if (zMin > zMax) {
        std::swap(zMin, zMax);
    }
    this->xMin = xMin;
    this->yMin = yMin;
    this->zMin = zMin;
    this->xMax = xMax;
    this->yMax = yMax;
    this->zMax = zMax;
}

Bounds::Bounds(Entity* min, Entity* max) {
    this->xMin = std::min(min->getPosition().getX(), max->getPosition().getX());
    this->yMin = std::min(min->getPosition().getY(), max->getPosition().getY());
    this->zMin = std::min(min->getPosition().getZ(), max->getPosition().getZ());
    this->xMax = std::max(min->getPosition().getX(), max->getPosition().getX());
    this->yMax = std::max(min->getPosition().getY(), max->getPosition().getY());
    this->zMax = std::max(min->getPosition().getZ(), max->getPosition().getZ());
}

Bounds::Bounds(UssVector min, UssVector max) {
    this->xMin = std::min(min.getX(), max.getX());
    this->yMin = std::min(min.getY(), max.getY());
    this->zMin = std::min(min.getZ(), max.getZ());
    this->xMax = std::max(min.getX(), max.getX());
    this->yMax = std::max(min.getY(), max.getY());
    this->zMax = std::max(min.getZ(), max.getZ());
}

bool Bounds::contains(Entity* point)
{
    return (point->getPosition().getX() >= xMin && point->getPosition().getX() <= xMax &&
            point->getPosition().getY() >= yMin && point->getPosition().getY() <= yMax &&
            point->getPosition().getZ() >= zMin && point->getPosition().getZ() <= zMax);
}


