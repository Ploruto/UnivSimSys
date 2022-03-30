#ifndef USimS_timedEvent
#define USimS_timedEvent
#include <UnivSim/event/Event.h>

class TimedEvent : public Event {
    public:
        TimedEvent(long long tick, Event* event);
        ~TimedEvent();
        
        long long getTick() const;
        void setTick(long long tick);
        Event* getEvent() const;
        
    private:
        long long m_tick;
        Event* m_event;
};

#endif