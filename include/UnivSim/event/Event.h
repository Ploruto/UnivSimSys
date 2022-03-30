#ifndef USimS_event
#define USimS_event

#include <UnivSim/entity/Entity.h>
#include <vector>

class Entity;

class Event {
    public:
        Event(){};
        ~Event();

        void emit_event();

    protected:
        std::vector<Entity*> m_receivers;
        
};

#endif