#include <gtest/gtest.h>
#include <UnivSim/entity/Entity.h>
#include <UnivSim/event/Event.h>
#include <iostream>

//create event deriving from event class
class TestEvent : public Event {
public:
    TestEvent(Entity* receiver, double number, int id) : Event(receiver), m_number(number), m_id(id) {}
    ~TestEvent() {}
    double getNumber() { return m_number; }
    int getId() { return m_id; }
private:
    double m_number;
    int m_id;
};

//create Entity deriving from Entity class
class TestEntity : public Entity {
public:
    TestEntity() : Entity() {}
    ~TestEntity() {}

    void receive_event(Event &event) {
        std::cout << "received general case" << std::endl;
    }

    void receive_event(TestEvent &event) {
        std::cout << "received special case" << std::endl;
    }
};

/*
calling receive_event with an Event which is not a method argument 
for receive_evnet but derives from Event will call the default Event case
*/

/*
void Entity::receive_event(Event &event) {
   std::cout << "received general case" << std::endl;
}*/

TEST(EntityTest, EntityEventTest){
    Entity* e = new Entity();
    TestEntity* te = new TestEntity();

    Event *event = new Event();
    event->add_entity(e);
    TestEvent *testEvent = new TestEvent(e, 1.0, 1);

    testEvent->add_entity(te);

    testEvent->emit_event();
    event->emit_event();
    
}