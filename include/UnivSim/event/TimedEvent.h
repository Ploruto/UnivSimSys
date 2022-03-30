#ifndef USimS_timedEvent
#define USimS_timedEvent
#include <UnivSim/event/Event.h>

class TimedEvent : public Event {
    public:
        TimedEvent(double tick, Event* event);
        virtual ~TimedEvent();
        
        long long getTick() const;
        void setTick(double tick);
        Event* getEvent() const;
        
    private:
        long long m_tick;
        Event* m_event;
};

#endif