#include <UnivSim/utils/math/UssVector.h>
#include <iostream>
#include <math.h>


UssVector::UssVector(double x, double y, double z): x(x), y(y), z(z){}
UssVector::UssVector(): x(0.0), y(0.0), z(0.0){}

double UssVector::getX() const {
    return this->x;
}

double UssVector::getZ() const{
    return this->z;
}

double UssVector::getY() const {
    return this->y;
}

bool UssVector::isEqual(const UssVector &v2) const{
    return (this->x == v2.x) && (this->y == v2.y) && (this->z == v2.z);
}

void UssVector::setVector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
    return;
}

UssVector UssVector::toUnitVector() const{
    double magnitute{sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2))};
    return UssVector(this->x / magnitute, this->y / magnitute, this->z / magnitute);
}

UssVector UssVector::getBasisVector(DIRECTION direction)
{
        switch (direction)
        {
        case UP:
            return UssVector(0,0,1);
        case DOWN:
            return UssVector(0,0,-1);
        case LEFT:
            return UssVector(0,-1,0);
        case RIGHT:
            return UssVector(0,1,0);
        case FORWARD:
            return UssVector(1,0,0);
        case BACKWARD:
            return UssVector(-1,0,0);
        default:
            return UssVector(-1,0,0);
        }

}

UssVector UssVector::operator+(const UssVector &v2) const{
    return UssVector(this->x + v2.x, this->y + v2.y, this->z + v2.z);
}

UssVector UssVector::operator-(const UssVector &v2) const{
    return UssVector(this->x - v2.x, this->y - v2.y, this->z - v2.z);
}

UssVector UssVector::operator*(double scalar) const{
    return UssVector(this->x * scalar, this->y * scalar, this->z * scalar);
}

UssVector UssVector::operator/(double scalar) const{
    return UssVector(this->x / scalar, this->y / scalar, this->z / scalar);
}

UssVector UssVector::operator=(const UssVector &v2){
    this->x = v2.x;
    this->y = v2.y;
    this->z = v2.z;
    return *this;
}
bool UssVector::operator== (const UssVector &v2) const{
    return (this->x == v2.getX()) && (this->y == v2.getY()) && (this->z == v2.getZ());
}

double UssVector::getCrossProduct(const UssVector &v) const{
    return (this->x * v.getY()) - (this->y * v.getX());
}

double UssVector::getDotProduct(const UssVector &v) const{
    return (this->x * v.getX()) + (this->y * v.getY()) + (this->z * v.getZ());
}

bool UssVector::isEqualDirection(const UssVector &v) const{
    UssVector v1{this->toUnitVector()};
    UssVector v2{v.toUnitVector()};
    return (v1.getCrossProduct(v2) == 0) && (v1.getDotProduct(v2) == 1);
}

double UssVector::getMagnitute() const{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

double UssVector::getDistance(const UssVector &v2) const{
    return sqrt(pow(this->x - v2.getX(), 2) + pow(this->y - v2.getY(), 2) + pow(this->z - v2.getZ(), 2));
}

double UssVector::getDistance(const UssVector &v1, const UssVector &v2){
    return sqrt(pow(v1.getX() - v2.getX(), 2) + pow(v1.getY() - v2.getY(), 2) + pow(v1.getZ() - v2.getZ(), 2));
}

