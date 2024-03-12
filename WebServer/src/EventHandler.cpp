#include "EventHandler.hpp"
#include "Reactor.hpp"

EventHandler::EventHandler(Reactor& reactor, int fd, const VirtualHostServer & virtualHostServer):
    reactor(reactor), fd(fd), virtualHostServer(virtualHostServer) {
}

EventHandler::EventHandler(const EventHandler & src):
    reactor(src.reactor), fd(src.fd), virtualHostServer(src.virtualHostServer){
}

EventHandler::~EventHandler() {}

EventHandler& EventHandler::operator=(const EventHandler &rhs) {
	if (this != &rhs) {
        this->fd = rhs.fd;
    }

	return (*this);
}
