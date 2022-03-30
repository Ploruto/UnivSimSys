#include <UnivSim/event/EventManager.h>
#include <UnivSim/event/TimedEvent.h>
#include <UnivSim/event/Event.h>


EventManager::EventManager() {}

EventManager::~EventManager() {
    removeAllTimedEvents();
}

void EventManager::removeTimedEvent(TimedEvent* event) {
    for (TimedEvent* e : timedEventsList) {
        if (e->getEvent() == event) {
            timedEventsList.remove(e);
            //delete e;
            return;
        }
    }
}

void EventManager::removeAllTimedEvents() {
    for (TimedEvent* e : timedEventsList) {
        //delete e;
    }
    timedEventsList.clear();
}

void EventManager::processTimedEvents(long long tick) {
    while (!timedEventsList.empty() && timedEventsList.front()->getTick() <= tick) {
        TimedEvent* e = timedEventsList.front();
        timedEventsList.pop_front();
        e->getEvent()->emit_event();
        //delete e;
    }
}

void EventManager::addTimedEvent(TimedEvent* event, long long tick) {
    TimedEvent* e = new TimedEvent(tick, event);
    if (timedEventsList.empty()) {
        timedEventsList.push_back(e);
        return;
    }
    std::list<TimedEvent*>::iterator it = timedEventsList.begin();
    while (it != timedEventsList.end() && (*it)->getTick() < tick) {
        it++;
    }
    timedEventsList.insert(it, e);
}