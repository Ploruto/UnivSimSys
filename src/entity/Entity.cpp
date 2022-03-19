#include <UnivSim/entity/Entity.h>


Entity::Entity() {
  m_perceptionVector = UssVector();
  m_movementVector = UssVector();
  m_position = UssVector();
}

Entity::Entity(UssVector &position) {
  m_perceptionVector = UssVector();
  m_movementVector = UssVector();
  m_position = position;
}

void Entity::receive_event() {
  // some code
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

UssVector Entity::getPerceptionVector() const {
  return m_perceptionVector;
}

UssVector Entity::getMovementVector() const{
  return m_movementVector;
}

UssVector Entity::getPosition() const{
  return m_position;
}


