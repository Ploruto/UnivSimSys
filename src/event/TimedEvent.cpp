#include <UnivSim/event/TimedEvent.h>
#include <UnivSim/event/Event.h>

TimedEvent::TimedEvent(long long tick, Event* event): m_tick(tick), m_event(event) {}

long long TimedEvent::getTick() const { return m_tick; }

void TimedEvent::setTick(long long tick) { m_tick = tick; }

Event* TimedEvent::getEvent() const { return m_event; }


