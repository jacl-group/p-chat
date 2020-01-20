//
// Created by cenicol on 7/21/19.
//

#include "PServer/DebugRequestHandler.hpp"

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"


using Poco::Util::Application;
using Poco::Net::HTTPServerResponse;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;

#include <sstream>

using namespace Poco::Net;
using namespace std;

DebugRequestHandler::DebugRequestHandler()
{
}

void DebugRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Application& app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);

    Timestamp now;
    std::string format = DateTimeFormat::SORTABLE_FORMAT;
    std::string dt(DateTimeFormatter::format(now, format));

    HTMLForm form(request, request.stream());

    std::string title{"DebugRequestHandler"};

    // HTML Response
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");

    std::ostream& ostr = response.send();
    ostr << "<html><head>";
    ostr << "<title>" << title << "</title>";
    ostr << "</head>";
    ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
    ostr << dt;
    ostr << "</p>";

    ostr << "<p>Request from: " << request.clientAddress().toString() << "</p>";
    ostr << "<p>Request to: " << request.serverAddress().toString() << "</p>";

    app.logger().information("Request from " + request.clientAddress().toString());
    app.logger().information("Request to " + request.serverAddress().toString());

    ostr << "<p>URI: " << request.getURI() << "</p>";

    ostr << "<p>" << "Response Size: " << request.size() << "</p>";
    ostr << "<ul>";
    for (auto item = request.begin(); item != request.end(); ++item) {
        ostr << "<li>" << item->first << ": " << item->second << "</li>";
    }
    ostr << "</ul>";

    ostr << "<p>Form Size: " << form.size() << "</p>";
    for(auto item = form.begin(); item != form.end(); ++item) {
        ostr << "<li>" << item->first << ": " << item->second << "</li>";
    }

    ostr << "</body></html>";
}
