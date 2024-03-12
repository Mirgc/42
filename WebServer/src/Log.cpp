#include <iostream>
#include <stdio.h>

#include "Log.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Log::Log()
{
}

Log::Log(const Log &log)
{
    *this = log;
}

Log::~Log()
{
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Log &Log::operator=(const Log &log)
{
    (void)log;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

void Log::error(const std::string &message)
{
    std::cout << "ERROR: " << message << std::endl;
}

void Log::debug(const std::string &message)
{
    std::cout << "DEBUG: " << message << std::endl;
}

void Log::socketList() {
    Log::socketList("");
}

void Log::socketList(const std::string& processFilter) {
    FILE* lsofFile = popen("lsof -i -n -P", "r");

    if (!lsofFile) {
        std::cerr << "Error executing lsof command" << std::endl;
        return;
    }

    // Display column headers
    std::cout << "PROCESS    PID  USER     FD  TYPE      DEVICE             SIZE/OFF  NODE    NAME" << std::endl;

    // Read and display socket information
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), lsofFile) != NULL) {
        std::string line(buffer);

        // Filter by process name
        if (processFilter.empty() || line.find(processFilter) != std::string::npos) {
            std::cout << line;
        }
    }

    pclose(lsofFile);
}

void Log::FD_PRINT(fd_set& set) {
    for (int i = 0; i < FD_SETSIZE; ++i) {
        if (FD_ISSET(i, &set)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
