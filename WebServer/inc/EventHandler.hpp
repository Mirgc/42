#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP
#include <netinet/in.h>

#include "VirtualHostServer.hpp"

class Reactor;

typedef enum e_event_handler_type
{
    EVENT_HANDLER_TYPE_NONE = 0,
    EVENT_HANDLER_TYPE_READ = 1,
    EVENT_HANDLER_TYPE_WRITE = 2
} t_event_handler_type;

class EventHandler {
public:
    EventHandler(Reactor& reactor, int fd, const VirtualHostServer & virtualHostServer);
    EventHandler(const EventHandler & src);
    virtual ~EventHandler();

    EventHandler & operator=(EventHandler const & rhs);

    virtual void handleEvent(const t_event_handler_type eventType = EVENT_HANDLER_TYPE_NONE) = 0;

protected:
    Reactor & reactor;
    int fd;
    VirtualHostServer virtualHostServer;
};

#endif
