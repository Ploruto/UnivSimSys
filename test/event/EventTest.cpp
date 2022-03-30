#include <UnivSim/entity/Entity.h>
#include <UnivSim/event/Event.h>
#include <UnivSim/event/TimedEvent.h>


TEST(EventTest, EventOperationTest){
    Event* e = new Event();
    EXPECT_EQ(e->getReceivers().size(), 0);
    e->addReceiver(new Entity());
    EXPECT_EQ(e->getReceivers().size(), 1);

}

