#include <UnivSim/utils/math/ussVector.h>
#include <iostream>
#include <math.h>


ussVector::ussVector(double x, double y, double z): x(x), y(y), z(z){}

double ussVector::getX() const {
    return this->x;
}

double ussVector::getZ() const{
    return this->z;
}

double ussVector::getY() const {
    return this->y;
}

bool ussVector::isEqual(const ussVector &v2){
    return (this->x == v2.x) && (this->y == v2.y) && (this->z == v2.z);
}

void ussVector::setVector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
    return;
}

ussVector ussVector::toUnitVector(){
    double magnitute{sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2))};
    return ussVector(this->x / magnitute, this->y / magnitute, this->z / magnitute);
}



ussVector ussVector::getBasisVector(DIRECTION direction)
{
        switch (direction)
        {
        case UP:
            return ussVector(0,0,1);
        case DOWN:
            return ussVector(0,0,-1);
        case LEFT:
            return ussVector(0,-1,0);
        case RIGHT:
            return ussVector(0,1,0);
        case FORWARD:
            return ussVector(1,0,0);
        case BACKWARD:
            return ussVector(-1,0,0);
        default:
            return ussVector(-1,0,0);
        }

}

ussVector ussVector::operator+(const ussVector &v2){
    return ussVector(this->x + v2.x, this->y + v2.y, this->z + v2.z);
}

ussVector ussVector::operator-(const ussVector &v2){
    return ussVector(this->x - v2.x, this->y - v2.y, this->z - v2.z);
}

ussVector ussVector::operator*(double scalar){
    return ussVector(this->x * scalar, this->y * scalar, this->z * scalar);
}

ussVector ussVector::operator/(double scalar){
    return ussVector(this->x / scalar, this->y / scalar, this->z / scalar);
}

ussVector ussVector::operator=(const ussVector &v2){
    this->x = v2.x;
    this->y = v2.y;
    this->z = v2.z;
    return *this;
}
bool ussVector::operator== (const ussVector &v2) const{
    return (this->x == v2.getX()) && (this->y == v2.getY()) && (this->z == v2.getZ());
}