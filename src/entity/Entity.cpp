#include <UnivSim/entity/Entity.h>


Entity::Entity() {
  m_perceptionVector = UssVector(0, 0, 0);
  m_movementVector = UssVector(0, 0, 0);
  m_position = UssVector(0, 0, 0);
}

Entity::Entity(UssVector &position) {
  m_perceptionVector = UssVector(0, 0, 0);
  m_movementVector = UssVector(0, 0, 0);
  m_position = position;
}

void Entity::receive_event() {
  // some code
}

void Entity::set_perception_vector(UssVector &perceptionVector) {
  m_perceptionVector = perceptionVector;
}

void Entity::set_movement_vector(UssVector &movementVector) {
  m_movementVector = movementVector;
}

void Entity::set_position(UssVector &position) {
  m_position = position;
}

UssVector Entity::get_perception_vector() {
  return m_perceptionVector;
}

UssVector Entity::get_movement_vector() {
  return m_movementVector;
}

UssVector Entity::get_position() {
  return m_position;
}


