#include <UnivSim/entity/Entity.h>
#include <gtest/gtest.h>
#include <UnivSim/event/EventReceiver.h>
#include <UnivSim/event/EventSource.h>

class EventTest
{
private:
    short m_testShort;
public:
    EventTest(short testShort): m_testShort(testShort) {}

    short getTestShort() const {
        return m_testShort;
    }
};

class NumberLover : public EventReceiver<EventTest> {
public:
    void receive_event(const EventTest &event) override {
        std::cout << "NumberLover received event with testShort: " << event.getTestShort() << std::endl;
    }
};

TEST(EventTest, EventCreation) {
    NumberLover numberLover;
    EventSource<EventTest> eventSource;
    eventSource.subscribe(&numberLover);
    EventTest event(5);
    eventSource.emit_event(event);

    eventSource.unsubscribe(&numberLover);
    eventSource.emit_event(event);

}




