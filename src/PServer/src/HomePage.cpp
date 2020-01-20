//
// Created by cenicol on 7/30/19.
//

#include "HomePage.hpp"

#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

HomePage::HomePage(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
        : HTMLPage(request, response) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
}

void HomePage::write(Poco::Net::HTMLForm *pForm) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);

    std::string title{"HomePage"};

    response_.setChunkedTransferEncoding(true);
    response_.setContentType("text/html");

    std::ostream &ostr = response_.send();
    ostr << "<html><head>";
    ostr << "<title>" << title << "</title>";
    ostr << R"END(
    <style>
</style>
)END";
    ostr << "</head><body>";
    ostr << R"END(
<h1>Home</h1>
<p>Need to choose a room to enter here.</p>
<p>Possibly other account maintenance stuff too.</p>
    )END";
    ostr << "</body>";
}
