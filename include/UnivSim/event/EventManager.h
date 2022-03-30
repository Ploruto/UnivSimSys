#ifndef USimS_eventManager
#define USimS_eventManager

#include <list>
#include <UnivSim/event/TimedEvent.h>
#include <UnivSim/event/Event.h>

class EventManager {
    public:
        EventManager();
        ~EventManager();

        void addTimedEvent(TimedEvent* event, long long tick); //O(n)
        void removeTimedEvent(TimedEvent* event); //O(n)
        void removeAllTimedEvents();
        void processTimedEvents(long long tick);


    public:
        std::list<TimedEvent*> timedEventsList; //sorted by tick in ascending order



        

};

#endif