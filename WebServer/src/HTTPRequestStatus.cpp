#include <sstream>

#include "HTTPRequestStatus.hpp"

HTTPRequestStatus::HTTPRequestStatus() {
	this->status = REQUEST_STATUS_WAITING;
}

HTTPRequestStatus::HTTPRequestStatus(const HTTPRequestStatus & src) {
    *this = src;
}

HTTPRequestStatus::~HTTPRequestStatus() {}

HTTPRequestStatus& HTTPRequestStatus::operator=(const HTTPRequestStatus &rhs) {
	if (this != &rhs) {
        this->status = rhs.status;
    }

	return (*this);
}

t_http_request_status HTTPRequestStatus::getStatus() {
	return (this->status);
}

void HTTPRequestStatus::setStatus(t_http_request_status status) {
	if (status < REQUEST_STATUS_WAITING || status > REQUEST_STATUS_CLOSED_ERROR) {
		std::runtime_error("HTTPRequestStatus::setStatus trying to set an invalid status.");
	}
	this->status = status;
}

std::string HTTPRequestStatus::toString(t_http_request_status status) {
    switch (status)
    {
	case REQUEST_STATUS_WAITING:
		return "REQUEST_STATUS_WAITING";
		break;
	case REQUEST_STATUS_READING_REQUEST:
		return "REQUEST_STATUS_READING_REQUEST";
		break;
	case REQUEST_STATUS_PROCESSING:
		return "REQUEST_STATUS_PROCESSING";
		break;
	case REQUEST_STATUS_PROCESSING_COMPLETE:
		return "REQUEST_STATUS_PROCESSING_COMPLETE";
		break;
	case REQUEST_STATUS_SENDING:
		return "REQUEST_STATUS_SENDING";
		break;
	case REQUEST_STATUS_SENDING_COMPLETE:
		return "REQUEST_STATUS_SENDING_COMPLETE";
		break;
	case REQUEST_STATUS_CLOSED_OK:
		return "REQUEST_STATUS_CLOSED_OK";
		break;
	case REQUEST_STATUS_CLOSED_ERROR:
		return "REQUEST_STATUS_CLOSED_ERROR";
		break;
    }

	std::runtime_error("HTTPRequestStatus::toString trying to print an invalid status.");
	return std::string();
}

HTTPRequestStatus::operator std::string() {
    std::ostringstream oss;
	oss << this->toString(this->getStatus());
    return oss.str();
}
