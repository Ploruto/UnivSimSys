#include <UnivSim/event/EventManager.h>
#include <UnivSim/event/TimedEvent.h>
#include <UnivSim/event/Event.h>


EventManager::EventManager() {}

EventManager::~EventManager() {
    removeAllTimedEvents();
}

EventManager::removeTimedEvent(Event* event) {
    for (TimedEvent* e : timedEventsList) {
        if (e->getEvent() == event) {
            timedEventsList.remove(e);
            delete e;
            return;
        }
    }
}

EventManager::removeAllTimedEvents() {
    for (TimedEvent* e : timedEventsList) {
        delete e;
    }
    timedEventsList.clear();
}

EventManager::processTimedEvents(long long tick) {
    while (!timedEventsList.empty() && timedEventsList.front()->getTick() <= tick) {
        TimedEvent* e = timedEventsList.front();
        timedEventsList.pop_front();
        e->getEvent()->emit_event();
        delete e;
    }
}

void EventManager::addTimedEvent(Event* event, long long tick) {
    TimedEvent* e = new TimedEvent(tick, event);
    if (timedEventsList.empty()) {
        timedEventsList.push_back(e);
        return;
    }
    for (TimedEvent* e : timedEventsList) {
        if (e->getTick() > tick) {
            timedEventsList.insert(e, e);
            return;
        }
    }
    timedEventsList.push_back(e);
}