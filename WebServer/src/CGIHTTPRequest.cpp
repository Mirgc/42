#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <signal.h>

#include "CGIHTTPRequest.hpp"
#include "HTTPResponse.hpp"
#include "HTTPResponse404.hpp"
#include "HTTPResponse500.hpp"
#include "HTTPResponse504.hpp"
#include "Path.hpp"

# define FD_IN 0
# define FD_OUT 1

CGIHTTPRequest::CGIHTTPRequest(
	const ServerConfig &serverConfig,
	const LocationConfig &location,
	const HTTPHeader &httpHeader,
    const HTTPBody & httpBody
) : HTTPRequest(serverConfig, location, httpHeader), httpBody(httpBody)
{
}

CGIHTTPRequest::CGIHTTPRequest(const CGIHTTPRequest &src)
	: HTTPRequest(src.serverConfig, src.location, src.httpHeader), httpBody(src.httpBody)
{
	*this = src;
}

CGIHTTPRequest::~CGIHTTPRequest() {}

CGIHTTPRequest &CGIHTTPRequest::operator=(const CGIHTTPRequest &rhs)
{
	(void)rhs;
    throw std::runtime_error("HTTP Request based classes are not allowed to be copied across.");
	return (*this);
}

// We need a way to clone a derived instance not knowing its derived form
CGIHTTPRequest *CGIHTTPRequest::clone()
{
	return (new CGIHTTPRequest(*this));
}

HTTPResponse CGIHTTPRequest::process()
{
	HTTPResponse response;

	try
	{
        std::string scriptPath = Path::concatenate(this->location.getDocroot(), this->httpHeader.getUrl());
        if (!Path::isFileAccessible(scriptPath))
        {
			return HTTPResponse404(this->serverConfig.get404Content());
        }

        std::string responseContent = this->execCGI(scriptPath, this->httpHeader.getQueryString());

		response.setResponse(responseContent);
	}
    catch (const std::runtime_error& e)
    {
        std::string error_message = e.what();
        if (error_message == "504") {
    		return HTTPResponse504(this->serverConfig.get504Content());
        }
		return HTTPResponse500(this->serverConfig.get500Content());
    }
    catch (...)
    {
		return HTTPResponse500(this->serverConfig.get500Content());
    }

	return (response);
}

std::string CGIHTTPRequest::execCGI(std::string cgiScriptRelativePath, std::string queryString)
{
    std::string output;

	// Build absolute path to the script we want to execute
	std::string cgiScriptAbsolutePath = getAbsolutePath(cgiScriptRelativePath);
	if (access(cgiScriptAbsolutePath.c_str(), X_OK) != 0) {
        throw std::runtime_error("CGI script does not exist or is not executable");
    }

    // As we need to send data from the webserver to the cgi, as well as from the cgi back to the
    // webserver, we need two pipes. As only one pipe for two ways comunication is unreliable, 
    // because of syncronization issues.
	int pipeCGIToWebserver[2];
	if (pipe(pipeCGIToWebserver) == -1) {
		throw std::runtime_error("Error calling pipe");
	}

	int pipeWebserverToCGI[2];
	if (pipe(pipeWebserverToCGI) == -1) {
		throw std::runtime_error("Error calling pipe");
	}

	pid_t pid = fork();
	if (pid == 0) {
		// We are at the child process to run the cgi
		std::string cgiInterpreter = "python3";
		std::string cgiInterpreterAbsolutePath = "/usr/bin/" + cgiInterpreter;
		
		char** args = createArgs(cgiInterpreter, cgiScriptAbsolutePath, queryString);
	    char** env = createEnvironment(cgiScriptAbsolutePath, queryString);

        close(pipeCGIToWebserver[FD_IN]);
        close(pipeWebserverToCGI[FD_OUT]);

        // Redirects web server output to the read end of the pipe. Parent process
        // will write here (pipeWebserverToCGI)
        if (dup2(pipeWebserverToCGI[FD_IN], STDIN_FILENO) == -1) {
            std::cout << "Error calling dup2 pipeWebserverToCGI[out], stdin" << std::endl;
            exit(EXIT_FAILURE);
        }
        close(pipeWebserverToCGI[FD_IN]);

        // Redirects cgi script output to the write end of the pipe, so webserver can read it.
        // Parent process will read from here(pipeCGIToWebserver)
        if (dup2(pipeCGIToWebserver[FD_OUT], STDOUT_FILENO) == -1) {
            std::cout << "Error calling dup2 pipeCGIToWebserver[in], stdout" << std::endl;
            exit(EXIT_FAILURE);
        }
        close(pipeCGIToWebserver[FD_OUT]);

        execve(cgiInterpreterAbsolutePath.c_str(), args, env);
		exit (EXIT_FAILURE);
	} else {
        close(pipeCGIToWebserver[FD_OUT]);
        close(pipeWebserverToCGI[FD_IN]);

		// If POST http request, they are passed to the script's standard input.
        if (this->httpHeader.getMethod() == "POST") {
            const std::vector<char> & httpRequestBody = this->httpBody.getFullBody();

            // Write the HTTP request body to the standard input of the child process
            ssize_t bytesWritten = write(pipeWebserverToCGI[FD_OUT], httpRequestBody.data(), httpRequestBody.size());
            if (!bytesWritten) {
                std::cout << " No body written to the CGI script " << std::endl;
            } else if (bytesWritten == -1) {
                throw std::runtime_error("Error could not write body to the CGI script");
            }
        }
        close(pipeWebserverToCGI[FD_OUT]);

        std::cout << " Waiting for CGI request to finish... " << std::endl;
		// We are at the main process waiting for child to finish.
		pid_t pidWaitingResult = 0;
		int status = 0;
        int numberAttemptsOnWaiting = 0;
        std::string httpCode = "";

        do {
            pidWaitingResult = waitpid(pid, &status, WNOHANG);
            if (pidWaitingResult == -1) {
        		std::cerr << "waitpid() error" << std::endl;
                httpCode = "500";
            }
            else if (pidWaitingResult == 0) {
                // CGI Proccess has NOT finished yet. Waiting ...
                sleep(1);
                numberAttemptsOnWaiting++;
                if (numberAttemptsOnWaiting > 30) {
                    kill(pid, SIGKILL);
                    std::cerr << "CGI Proccess exceeded max waiting time." << std::endl;
                    httpCode = "504";
                    break;
                }
            }
            else {
                std::cout << "CGI Proccess has finished with status " << status << std::endl;
                if (status != 0) {
                    httpCode = "500";
                }

                output = readFromPipe(pipeCGIToWebserver[FD_IN]);
            }
        } while (pidWaitingResult == 0);

        close(pipeCGIToWebserver[FD_IN]);

        if (!httpCode.empty()) {
            throw std::runtime_error(httpCode);
        }
	}
    
	return (output);
}

std::string CGIHTTPRequest::getAbsolutePath(const std::string& relativePath) {
    char cwd[FILENAME_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::ostringstream oss;
        oss << cwd << "/" << relativePath;
        std::string absolutePath = oss.str();
        if (absolutePath.size() < sizeof(cwd)) {
            return absolutePath;
        } else {
            throw std::runtime_error("Absolute path too long");
        }
    } else {
        throw std::runtime_error("Error calling getcwd");
    }
}

char** CGIHTTPRequest::createEnvironment(
    const std::string& cgiScriptAbsolutePath,
    const std::string& queryString
) {
    std::vector<std::string> env;

	// In the RFC this is called meta-variables (Parameters passed to the CGI through the environment)
	// https://datatracker.ietf.org/doc/html/rfc3875.html#section-4.1

    env.push_back("REQUEST_METHOD=" + this->httpHeader.getMethod());

	// Path to the cgi script to be executed
    env.push_back("PATH_INFO=" + cgiScriptAbsolutePath);
    env.push_back("SCRIPT_NAME=" + cgiScriptAbsolutePath);

	// The QUERY_STRING variable contains a URL-encoded search or parameter string
    env.push_back("QUERY_STRING=" + queryString);

	// The CONTENT_LENGTH variable contains the size of the message-body attached to the request
	// Guess if we have a POST (document upload, form, etc), that would be the lenght of the body POST?
    env.push_back("CONTENT_LENGTH=" + this->httpBody.getBodySizeString());
    env.push_back("CONTENT_TYPE=" + this->httpHeader.getHeaderValueWithKey("Content-Type"));

	// The SERVER_NAME variable MUST be set to the name of the server host to which the client request is directed.
    env.push_back("SERVER_NAME=" + this->serverConfig.getServerName());

    env.push_back("GATEWAY_INTERFACE=CGI/1.1");
    env.push_back("SERVER_PROTOCOL=HTTP/1.0");

	return createCharPtrArray(env);
}

char** CGIHTTPRequest::createArgs(const std::string& cgiInterpreter, const std::string& cgiScriptAbsolutePath, const std::string& queryString) {
	std::vector<std::string> args;
    args.push_back(cgiInterpreter);
    args.push_back(cgiScriptAbsolutePath);
    args.push_back(queryString);

	return createCharPtrArray(args);
}

char** CGIHTTPRequest::createCharPtrArray(const std::vector<std::string>& strings) {
    char** result = new char*[strings.size() + 1];
    for (size_t i = 0; i < strings.size(); ++i) {
        result[i] = new char[strings[i].length() + 1];
        strcpy(result[i], strings[i].c_str());
    }
    result[strings.size()] = NULL;
    return result;
}

std::string CGIHTTPRequest::readFromPipe(int pipefd) {
    char buffer[1024];
    ssize_t bytesRead;
    std::string output = "";
    while ((bytesRead = read(pipefd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        output.append(buffer);
    }

    if (bytesRead == -1) {
        std::cout << "CGI error reading cgi script output." << std::endl;
    }

    return output;
}
