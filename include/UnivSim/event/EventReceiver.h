#ifndef USimS_eventReceiver
#define USimS_eventReceiver

template <class EventType>
class EventReceiver {
    private:
        long long m_uuid;
    
    private:
        static long long getNextUUID() {
            static long long uuid{0};
            return uuid++;
        }

    public:
        virtual void receive_event(const EventType &event) = 0;

        EventReceiver() : m_uuid(getNextUUID()) {}

        long long getUUID() const {
            return m_uuid;
        }
};

#endif