#ifndef USimS_eventReceiver
#define USimS_eventReceiver

template <class EventType>
class EventReceiver {
    public:
        virtual void receive_event(const EventType &event) = 0;
};

#endif