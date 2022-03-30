#include <UnivSim/event/Event.h>
#include <UnivSim/entity/Entity.h>

Event::emit_event() {
    for (Entity* e : m_receivers) {
        e->receive_event(this);
    }
}