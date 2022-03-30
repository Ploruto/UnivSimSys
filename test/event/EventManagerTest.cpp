#include <gtest/gtest.h>
#include <UnivSim/event/EventManager.h>
#include <UnivSim/event/TimedEvent.h>
#include <UnivSim/event/Event.h>

TEST(EventManagerTest, EventManagerOperations){
    EventManager* em = new EventManager();
    Event* e = new Event();
    TimedEvent* te = new TimedEvent(5, e);
    em->addTimedEvent(te, te->getTick());
    
    EXPECT_EQ(em->timedEventsList.size(), 1);
    EXPECT_EQ(em->timedEventsList.front()->getTick(), 5);

    em->processTimedEvents(4);
    EXPECT_EQ(em->timedEventsList.size(), 1);

    em->processTimedEvents(5);
    EXPECT_EQ(em->timedEventsList.size(), 0);
    
}