#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdexcept>

#include <fstream>
#include <iostream>

#include "VirtualHostServer.hpp"
#include "AcceptConnectionEventHandler.hpp"

VirtualHostServer::VirtualHostServer(Reactor &reactor, const ServerConfig &config) : reactor(reactor), config(config)
{
}

VirtualHostServer::VirtualHostServer(const VirtualHostServer &src) : reactor(src.reactor)
{
    *this = src;
}

VirtualHostServer::~VirtualHostServer() {}

VirtualHostServer &VirtualHostServer::operator=(const VirtualHostServer &rhs)
{
    if (this != &rhs)
    {
        this->config = rhs.config;
        this->listenSocket = rhs.listenSocket;
    }
    return (*this);
}

void VirtualHostServer::start()
{
    int size = this->getServerConfig().getListenPortsSize();
    // Create a socket for listening
    for (int i = 0; i < size; i++)
    {
        listenSocket.push_back(socket(AF_INET, SOCK_STREAM, 0));
        if (listenSocket[i] < 0)
        {
            this->stop();
            throw std::runtime_error("Failed to create a listening socket");
        }
    }
    // Set up the address for IP4 on 0.0.0.0:port
    struct sockaddr_in tmpAddress;
    memset(&tmpAddress, 0, sizeof(tmpAddress));
    for (int x = 0; x < size; x++)
    {
        tmpAddress.sin_family = AF_INET;
        tmpAddress.sin_addr.s_addr = htonl(config.getHost());
        // "getPortAt()"" retrieves the value at a specific position from the "_listendPorts" vector.
        // Should we iterate to change the value before binding, or should we instantiate a new `VirtualHostServer` for each port?
        tmpAddress.sin_port = htons(config.getPortAt(x));
        Address.push_back(tmpAddress);
        memset(&tmpAddress, 0, sizeof(tmpAddress));
    }
    int reuse = 1;
    for (int l = 0; l < size; l++)
    {
        if (setsockopt(listenSocket[l], SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0)
        {
            this->stop();
            throw std::runtime_error("Failed to set socket option");
        }
    }
    // Bind the sockets to the address

    for (int i = 0; i < size; i++)
    {
        if (bind(listenSocket[i], (struct sockaddr *)&Address[i], sizeof(Address[i])) < 0)
        {
            this->stop();
            throw std::runtime_error("Failed to bind the listening socket");
        }
    }
    listen();
}

void VirtualHostServer::listen()
{
    // Start listening for incoming connections
    int size = this->getServerConfig().getListenPortsSize();
    for (int i = 0; i < size; i++)
    {
        // Start listening for incoming connections
        if (::listen(listenSocket[i], SOMAXCONN) == -1)
        {
            this->stop();
            throw std::runtime_error("Failed to start listening on the socket");
        }
        std::cout << "Registering event (fd = " << listenSocket[i] << ") AcceptConnectionEventHandler" << std::endl;

        // This handler will accept new connections to this Server/VirtualHost
        EventHandler *acceptNewConnectionHandler = new AcceptConnectionEventHandler(reactor, listenSocket[i], *this, this->getAddress(i));
        reactor.registerEventHandler(listenSocket[i], acceptNewConnectionHandler);
    }
}

void VirtualHostServer::stop()
{
    std::cout << "VirtualHostServer::stop() Shutting the virtual server down..." << std::endl;

    if (!listenSocket.empty())
    {
        for (std::vector<int>::size_type i = 0; i < listenSocket.size(); ++i)
        {
            this->reactor.unregisterEventHandler(listenSocket[i]);
            close(listenSocket[i]);
            listenSocket[i] = 0;
        }
    }
    listenSocket.clear();
}

struct sockaddr_in VirtualHostServer::getAddress(int i)
{
    return (Address[i]);
}

const ServerConfig &VirtualHostServer::getServerConfig() const
{
    return (this->config);
}
