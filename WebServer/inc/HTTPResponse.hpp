#ifndef HTTP_RESPONSE_HPP
#define HTTP_RESPONSE_HPP

#include <string>
#include <vector>

class HTTPResponse {
public:
    HTTPResponse();
    HTTPResponse(const HTTPResponse & src);
    virtual ~HTTPResponse();

    HTTPResponse & operator=(HTTPResponse const & rhs);

    void setResponse(const std::vector<char> & response);
    void setResponse(const std::string & ss);
    const std::vector<char> & getFullResponse();
    std::vector<char> getNextResponseChunkToBeSent();
    ssize_t getResponseSize();

    ssize_t getTotalBytesSentToClient();
    void addBytesSentToClient(ssize_t bytesSentToClient);
    bool isRequestFullySent();

private:

    std::vector<char> response;
    ssize_t totalBytesSentToClient;
};

#endif
