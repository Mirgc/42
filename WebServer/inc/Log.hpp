#ifndef LOG_HPP
#define LOG_HPP

#include <string>
#include <sys/time.h>

class Log
{
public:
    Log(void);
    Log(const Log &log);
    ~Log();

    Log &operator=(const Log &log);

    static void error(const std::string &message);
    static void debug(const std::string &message);
    static void socketList();
    static void socketList(const std::string& processFilter);
    static void FD_PRINT(fd_set& set);

};

#endif
