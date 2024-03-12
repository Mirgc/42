#include <iostream>
#include <vector>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include "Reactor.hpp"
#include "EventHandler.hpp"
#include "Log.hpp"

Reactor* Reactor::_instance = NULL;

Reactor::Reactor() {
    this->bRunEventLoop = true;
}

// Official patter sugests makeing this a singleton to avoid having multiple instances of Reactor
Reactor* Reactor::getInstance(){
if (NULL == _instance)
    _instance = new Reactor();
return _instance;
}

Reactor::Reactor(const Reactor & src) {
	*this = src;
}

Reactor::~Reactor() {}

Reactor& Reactor::operator=(const Reactor &rhs) {
    
	if (this != &rhs) {
        throw std::runtime_error("Reactor must be a Singleton and this case should never happen");
	}
	
	return (*this);
}

void Reactor::runEventLoop() {
    fd_set readSet;
    fd_set writeSet;
    int maxFd = 0;



    // We will need to deal with ending this loop to free up and gracefully exit
    while (this->bRunEventLoop) {
        maxFd = 0;
        FD_ZERO(&readSet);
        FD_ZERO(&writeSet);

        // Collects all registered socket fds
        for (std::map<int, EventHandler*>::iterator it = fdHandlerMap.begin(); it != fdHandlerMap.end(); ++it) {
            int fd = it->first;
            FD_SET(fd, &readSet);
            FD_SET(fd, &writeSet);
            if (fd > maxFd) {
                maxFd = fd;
            }
        }

        std::cout << std::endl << "select() is checking these fds: ";
        Log::FD_PRINT(readSet);
        Log::socketList("webserv");
        std::cout << std::endl;

        // Checks whether any socket has data
        int numReady = select(maxFd + 1, &readSet, &writeSet, NULL, NULL);

        if (numReady == -1) {
            std::cerr << "select() error -1." << std::endl;
            break;
        }
        // Any with data?
        if (numReady > 0) {
            // Elements can get deleted from the map as we loop through it. Find a better solution
            for (std::map<int, EventHandler*>::iterator it = fdHandlerMap.begin(); it != fdHandlerMap.end(); ++it) {
                int fd = it->first;
                if (FD_ISSET(fd, &readSet) || FD_ISSET(fd, &writeSet)) {

                    // Socket fd has data, disptach the event to the right handler
                    EventHandler* handler = it->second;
                    if (!handler) {
                        continue;
                    }

                    try {
                        if (FD_ISSET(fd, &readSet)) {
                            std::cout << std::endl << "Socket (" << fd << ") is ready to read data" << std::endl;
                            handler->handleEvent(EVENT_HANDLER_TYPE_READ);
                        } else if (FD_ISSET(fd, &writeSet)) {
                            std::cout << std::endl << "Socket (" << fd << ") is ready to write data" << std::endl;
                            handler->handleEvent(EVENT_HANDLER_TYPE_WRITE);
                        } else {
                            std::runtime_error("Reactor::runEventLoop not read ready nor write ready. Internal error!");
                        }
                    }
                    catch(...) {
                        this->unregisterEventHandler(fd);
                    }
                }
            }
        }
        deleteUnregisteredHandlers();
    }
}

void Reactor::stopEventLoop() {
    this->bRunEventLoop = false;
}

void Reactor::registerEventHandler(int fd, EventHandler* handler) {
    fdHandlerMap[fd] = handler;
}

void Reactor::unregisterEventHandler(int fd) {

    std::cout << "Reactor unregistering socket (" << fd << ")" << std::endl;

    std::map<int, EventHandler*>::iterator it = fdHandlerMap.find(fd);
    if (it != fdHandlerMap.end()) {
        // Deferrs the deleting of EventHandler instance and closing of the socket
        this->handlersToDelete.push_back(it->first);
    }
    else
    {
        std::runtime_error("Reactor::unregisterEventHandler: Error unregistering handler.");
    }
}

void Reactor::deleteUnregisteredHandlers() {

    if (!handlersToDelete.size()) {
        return ;
    }

    for (size_t i = 0; i < handlersToDelete.size(); ++i) {
        if (handlersToDelete[i]) {
            try {
                std::map<int, EventHandler*>::iterator it = fdHandlerMap.find(handlersToDelete[i]);
                if (it != fdHandlerMap.end()) {
                    // Deletes the Event Handler instance
                    delete it->second;
                    // Closes the fd
                    close(it->first);
                    // Removes the fd, EventHandler from the map
                    fdHandlerMap.erase(it);
                }
            }
            catch (...) {
                std::runtime_error("Reactor::deleteUnregisteredHandlers: Error deleting instance.");
            }
        }
    }

    handlersToDelete.clear();
}
