#ifndef VIRTUAL_HOST_SERVER_HPP
#define VIRTUAL_HOST_SERVER_HPP

#include "Reactor.hpp"
#include "ServerConfig.hpp"

class VirtualHostServer
{
public:
    VirtualHostServer(Reactor &reactor, const ServerConfig &config);
    VirtualHostServer(const VirtualHostServer &src);
    ~VirtualHostServer();

    VirtualHostServer &operator=(VirtualHostServer const &rhs);

    struct sockaddr_in getAddress(int i);
    void start();
    void stop();
    const ServerConfig &getServerConfig() const;

private:
    void listen();

    Reactor &reactor;
    ServerConfig config;
    std::vector<int> listenSocket;
    std::vector<struct sockaddr_in> Address;
};

#endif
