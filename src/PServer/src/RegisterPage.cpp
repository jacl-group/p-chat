//
// Created by cenicol on 7/30/19.
//

#include "RegisterPage.hpp"


#include "Poco/Util/ServerApplication.h"
#include "Poco/Net/HTTPServerRequest.h"
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

RegisterPage::RegisterPage(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
        : HTMLPage(request, response) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
}

void RegisterPage::write(Poco::Net::HTMLForm *pForm) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);

    std::string title{"RegisterPage"};

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
<h1>Register New Username</h1>
<form action="validate" method="post">
<table>
<tr><th>Username</th><td><input type="text" name="username"></td></tr>
<tr><th>Password</th><td><input type="text" name="password"></td></tr>
<tr><th>Again</th><td><input type="text" name="again"></td></tr>
<tr><th>EMail</th><td><input type="text" name="email"></td></tr>
<tr><td colspan=2><input type="submit" name="action" value="Register"></td></tr>
</table>
</form>
)END";

    ostr << "</body>";
}