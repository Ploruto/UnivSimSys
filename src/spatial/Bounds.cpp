#include <UnivSim/spatial/Bounds.h>
#include <UnivSim/spatial/EntityPoint.h>
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

Bounds::Bounds(EntityPoint min, EntityPoint max) {
    this->xMin = std::min(min.getX(), max.getX());
    this->yMin = std::min(min.getY(), max.getY());
    this->zMin = std::min(min.getZ(), max.getZ());
    this->xMax = std::max(min.getX(), max.getX());
    this->yMax = std::max(min.getY(), max.getY());
    this->zMax = std::max(min.getZ(), max.getZ());

}

bool Bounds::contains(EntityPoint point)
{
    return (point.getX() >= xMin && point.getX() <= xMax &&
            point.getY() >= yMin && point.getY() <= yMax &&
            point.getZ() >= zMin && point.getZ() <= zMax);
}


