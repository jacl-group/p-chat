//
// Created by cenicol on 7/31/19.
//

#include "ValidatePage.hpp"

#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

ValidatePage::ValidatePage(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
        : HTMLPage(request, response) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
}

void ValidatePage::write(Poco::Net::HTMLForm *pForm) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);

    std::string title{"ValidatePage"};

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
<p>Validate Code</p>
<form action="validate">
<table>
<tr><td>Code:</td><td><input type="text" name="code"></td><td><input type="submit" name="validate" value="Validate"</td></tr>
<tr><td colspan="3"><a href="/validate?resend">Resend validation code to your email.</a></td></tr>
</table>
</form>
)END";

    ostr << "</body>";
}
