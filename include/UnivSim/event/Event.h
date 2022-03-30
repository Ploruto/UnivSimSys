#ifndef USimS_event
#define USimS_event

#include <UnivSim/entity/Entity.h>
#include <vector>

class Event {
    public:
        Event(){};
        virtual ~Event() = 0;

        void emit_event();

    protected:
    //ToDo: fix this compiler error
        std::vector<Entity*> m_receivers;
        
};

#endif