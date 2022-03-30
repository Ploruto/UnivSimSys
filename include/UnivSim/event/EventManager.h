#ifndef USimS_eventManager
#define USimS_eventManager

#include <list>
#include <UnivSim/event/TimeEvent.h>
#include <UnivSim/event/Event.h>

class EventManager {
    public:
        EventManager();
        ~EventManager();

        void addTimedEvent(Event* event, long long tick); //O(n)
        void removeTimedEvent(Event* event); //O(n)
        void removeAllTimedEvents();
        void processTimedEvents(long long tick);

    private:
        std::list<TimedEvent> timedEventsList; //sorted by tick in ascending order
        


        

};

#endif