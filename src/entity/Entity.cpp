#include <UnivSim/entity/Entity.h>


long long Entity::getNextUUID() {
    static long long uuid{0};
    return uuid++;
}

Entity::Entity() {
    m_perceptionVector = UssVector();
    m_movementVector = UssVector();
    m_position = UssVector();
    m_uuid = getNextUUID();
    m_aabb = new AABB(this, 0.0f, 0.0f, 0.0f);
}

Entity::Entity(UssVector &position, UssVector &perceptionVector, UssVector &movementVector):
    m_perceptionVector(perceptionVector),
    m_movementVector(movementVector),
    m_position(position),
    m_uuid(getNextUUID())
{
}

Entity::Entity(AABB* aabb):
    m_perceptionVector(UssVector()),
    m_movementVector(UssVector()),
    m_position(UssVector()),
    m_uuid(getNextUUID()),
    m_aabb(aabb)
{
}

void Entity::setPerceptionVector(UssVector &perceptionVector) {
    m_perceptionVector = perceptionVector;
}

void Entity::setMovementVector(UssVector &movementVector) {
    m_movementVector = movementVector;
}

void Entity::setPosition(UssVector &position) {
    m_position = position;
}

void Entity::setPosition(float x, float y, float z) {
    m_position = UssVector(x, y, z);
}

UssVector Entity::getPerceptionVector() const {
    return m_perceptionVector;
}

UssVector Entity::getMovementVector() const {
    return m_movementVector;
}

UssVector Entity::getPosition() const {
    return m_position;
}


