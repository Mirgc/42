#include "MIMETypes.hpp"
/* orthodox canonical class form requirement */

MIMETypes::MIMETypes(void)
{
}

MIMETypes::MIMETypes(MIMETypes const &src)
{
    *this = src;
}

MIMETypes::~MIMETypes(void)
{
}

MIMETypes &MIMETypes::operator=(MIMETypes const &rhs)
{
    (void) rhs;
    return (*this);
}

std::string MIMETypes::getContentType(std::string str)
{
    std::map<std::string, std::string> extensionToContentType;
    extensionToContentType[".aac"] = "audio/aac";
    extensionToContentType[".abw"] = "application/x-abiword";
    extensionToContentType[".arc"] = "application/octet-stream";
    extensionToContentType[".avi"] = "video/x-msvideo";
    extensionToContentType[".azw"] = "application/vnd.amazon.ebook";
    extensionToContentType[".bin"] = "application/octet-stream";
    extensionToContentType[".bz"] = "application/x-bzip";
    extensionToContentType[".bz2"] = "application/x-bzip2";
    extensionToContentType[".csh"] = "application/x-csh";
    extensionToContentType[".css"] = "text/css";
    extensionToContentType[".csv"] = "text/csv";
    extensionToContentType[".doc"] = "application/msword";
    extensionToContentType[".eot"] = "application/vnd.ms-fontobject";
    extensionToContentType[".epub"] = "application/epub+zip";
    extensionToContentType[".gif"] = "image/gif";
    extensionToContentType[".htm"] = "text/html";
    extensionToContentType[".html"] = "text/html";
    extensionToContentType[".ico"] = "image/x-icon";
    extensionToContentType[".ics"] = "text/calendar";
    extensionToContentType[".jar"] = "application/java-archive";
    extensionToContentType[".jpeg"] = "image/jpeg";
    extensionToContentType[".jpg"] = "image/jpeg";
    extensionToContentType[".js"] = "application/javascript";
    extensionToContentType[".json"] = "application/json";
    extensionToContentType[".mid"] = "audio/midi";
    extensionToContentType[".midi"] = "audio/midi";
    extensionToContentType[".mpeg"] = "video/mpeg";
    extensionToContentType[".mpkg"] = "application/vnd.apple.installer+xml";
    extensionToContentType[".odp"] = "application/vnd.oasis.opendocument.presentation";
    extensionToContentType[".ods"] = "application/vnd.oasis.opendocument.spreadsheet";
    extensionToContentType[".odt"] = "application/vnd.oasis.opendocument.text";
    extensionToContentType[".oga"] = "audio/ogg";
    extensionToContentType[".ogv"] = "video/ogg";
    extensionToContentType[".ogx"] = "application/ogg";
    extensionToContentType[".otf"] = "font/otf";
    extensionToContentType[".png"] = "image/png";
    extensionToContentType[".pdf"] = "application/pdf";
    extensionToContentType[".ppt"] = "application/vnd.ms-powerpoint";
    extensionToContentType[".rar"] = "application/x-rar-compressed";
    extensionToContentType[".rtf"] = "application/rtf";
    extensionToContentType[".sh"] = "application/x-sh";
    extensionToContentType[".svg"] = "image/svg+xml";
    extensionToContentType[".swf"] = "application/x-shockwave-flash";
    extensionToContentType[".tar"] = "application/x-tar";
    extensionToContentType[".tif"] = "image/tiff";
    extensionToContentType[".tiff"] = "image/tiff";
    extensionToContentType[".ts"] = "video/vnd.dlna.mpeg-tts";
    extensionToContentType[".ttf"] = "font/ttf";
    extensionToContentType[".vsd"] = "application/vnd.visio";
    extensionToContentType[".wav"] = "audio/x-wav";
    extensionToContentType[".weba"] = "audio/webm";
    extensionToContentType[".webm"] = "video/webm";
    extensionToContentType[".webp"] = "image/webp";
    // Extract the file extension from the filename
    size_t dotPosition = str.find_last_of(".");
    if (dotPosition != std::string::npos)
    {
        std::string ctExtension = str.substr(dotPosition);
        // Look up the extension in the map
        std::map<std::string, std::string>::iterator it = extensionToContentType.find(ctExtension);
        if (it != extensionToContentType.end())
        {
            return it->second;
        }
    }
    return "application/octet-stream";
}
