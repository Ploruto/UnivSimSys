#ifndef USimS_eventSource
#define USimS_eventSource

#include <unordered_map>

template <class EventType>
class EventSource {
    public:
        using ReceiverType = EventReceiver<EventType>;
    private:
        std::unordered_map<long long, ReceiverType*> m_subscribers; //key is the uuid of the receiver

    public:
        void subscribe(ReceiverType* receiver) {
            m_subscribers[receiver->getUUID()] = receiver;
        }

        void unsubscribe(ReceiverType* receiver) {
            m_subscribers.erase(receiver->getUUID());
        }

        
        void emit_event(const EventType &event) {
            for (auto &subscriber : m_subscribers) {
                subscriber->receive_event(event);
            }
        }

};

#endif