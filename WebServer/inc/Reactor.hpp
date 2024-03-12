#ifndef REACTOR_HPP
# define REACTOR_HPP

#include <map>
#include <vector>
#include <utility>  // For std::pair
#include <cstring>

class EventHandler;

// Official patter sugests makeing this a singleton to avoid having multiple instances of Reactor
class Reactor {
public:
    static Reactor* getInstance();
    
    ~Reactor();
    void runEventLoop();
    void stopEventLoop();
    void registerEventHandler(int fd, EventHandler* handler);
    void unregisterEventHandler(int fd);
    void deleteUnregisteredHandlers();

private:
    Reactor();
	// I make private the copy and the operator to avoid the creation of new instances
    Reactor(const Reactor & src); 
    Reactor & operator=(Reactor const & rhs);
    // Holds all registered event handlers <SocketFD, EventHandler>
    std::map<int, EventHandler*> fdHandlerMap;
    // Garbage collector (indexed by fd) so that instances can unregister themselves on a deferred basis
    std::vector<int> handlersToDelete;

    static Reactor *_instance;
    bool bRunEventLoop;
};

#endif
