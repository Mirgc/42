#ifndef ACCEPT_CONNECTION_EVENT_HANDLER_HPP
# define ACCEPT_CONNECTION_EVENT_HANDLER_HPP

class Reactor;

#include "EventHandler.hpp"

class AcceptConnectionEventHandler: public EventHandler {
public:
    AcceptConnectionEventHandler(
        Reactor& reactor,
        int fd,
        const VirtualHostServer & virtualHostServer,
        struct sockaddr_in socketAddress
    );
    AcceptConnectionEventHandler(const AcceptConnectionEventHandler & src);
    ~AcceptConnectionEventHandler();

    AcceptConnectionEventHandler & operator=(AcceptConnectionEventHandler const & rhs);

    void handleEvent(const t_event_handler_type eventType = EVENT_HANDLER_TYPE_NONE);

private:
    struct sockaddr_in socketAddress;

};

#endif
