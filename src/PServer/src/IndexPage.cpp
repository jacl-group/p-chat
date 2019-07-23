//
// Created by cenicol on 7/23/19.
//

#include "include/PServer/IndexPage.hpp"

#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <Poco/Net/HTTPServerResponse.h>
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"

using Poco::Util::Application;
using Poco::Net::HTTPServerResponse;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;

void IndexPage::write(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    Application& app = Application::instance();
    app.logger().information("Request from " + request.clientAddress().toString());

    Timestamp now;
    std::string format = DateTimeFormat::SORTABLE_FORMAT;
    std::string dt(DateTimeFormatter::format(now, format));

    std::string title{"IndexPage"};

    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");

    std::ostream& ostr = response.send();
    ostr << "<html><head>";
    ostr << "<title>" << title << "</title>";
    ostr << R"END(
<style>
td.button {
  text-align: center;
  column-span: 2;
}
</style>
)END";
    ostr << "</head>";
    ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
    ostr << dt;
    ostr << "</p>";

    ostr << R"END(
<p>The welcome page which is basically index.html</p>
<p>Other things can be placed on this page, but the minimum is a way to login to the site.</p>
)END";

    ostr << R"END(
<form action=\"signin\" method=\"post\">
<table>
<tr><td>Username:</td><td><input type="text" name="username"></input></td></tr>
<tr><td>Password:</td><td><input type="password" name="password"></input></td></tr>
<tr><td class="button" colspan="2"><input type="submit" name="action" value="Login"></td></tr>
<tr><td class="button" colspan="2">or <input type="submit" name="action" value="Register"></td></tr>
</table>
</form>
)END";

    ostr << "</body></html>";
}
