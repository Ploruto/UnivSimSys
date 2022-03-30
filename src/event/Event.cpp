#include <UnivSim/event/Event.h>
#include <UnivSim/entity/Entity.h>

void Event::emit_event() {
    for (Entity* e : m_receivers) {
        e->receive_event(*this);
    }
}

void Event::add_entity(Entity* entity) {
    m_receivers.push_back(entity);
}

std::vector<Entity*> Event::getReceivers() const {
    return m_receivers;
}