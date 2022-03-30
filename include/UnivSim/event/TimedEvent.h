#ifndef USimS_timedEvent
#define USimS_timedEvent
#include <UnivSim/event/Event.h>

template<class TEvent>
class TimedEvent : public Event {
    public:
        TimedEvent(double tick, TEvent &event): m_tick(tick), m_event(event) {};
        virtual ~TimedEvent();
        
        double getTick() const { return m_tick; }
        void setTick(double tick){ m_tick = tick; }

        TEvent getEvent() const { return m_event; }
        
    private:
        long long m_tick;
        TEvent m_event;
};

#endif