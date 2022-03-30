#ifndef USimS_timedEvent
#define USimS_timedEvent
#include <UnivSim/event/Event.h>

template<class TEvent>
class TimedEvent : public Event {
    public:
        TimedEvent(double tick);
        virtual ~TimedEvent();
        
        double getTick() const;
        void setTick(double tick);

        TEvent getEvent() const;
        
    private:
        long long m_tick;
        TEvent m_event;
};

#endif