#ifndef USimS_event
#define USimS_event

#include <UnivSim/entity/Entity.h>
#include <vector>

class Entity;

class Event {
    public:
        Event(){};
        Event(Entity* receiver);
        ~Event();

        void emit_event();
        void add_entity(Entity* entity);
        std::vector<Entity*> getReceivers() const;

    protected:
        std::vector<Entity*> m_receivers;
        
};

#endif