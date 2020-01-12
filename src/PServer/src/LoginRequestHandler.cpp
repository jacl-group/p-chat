//
// Created by cenicol on 7/30/19.
//

#include "SigninRequestHandler.hpp"
#include "IndexPage.hpp"
#include "HomePage.hpp"
#include <RegisterPage.hpp>
#include <PServer/validation_error.hpp>

#include <Poco/LogStream.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

using namespace Poco::Net;
using namespace std;

void
SigninRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
    Poco::LogStream lstr(app.logger());

    HTMLForm form(request, request.stream());

    string method = request.getMethod();
    lstr << "method: " << method << endl;
    if (method != "POST") {
        lstr.error() << "Invalid method: " << method << endl;
        form.add("comment", "method != POST");
        IndexPage(request, response)(&form);
        return;
    }

#if 1
    lstr << "Form:" << endl;
    for (auto it : form) {
        lstr << "\t" << it.first << ": " << (it.second.empty() ? "empty" : it.second) << endl;
    }
#endif

    try {
        string action{};
        auto it = form.get("action");
        //if (it != form.end()) {
        //    action = form.get("action");
        //}
        cout << "action: " << (action.empty() ? "empty" : action) << endl;

        if (action.empty()) {
            IndexPage(request, response)(&form);
            return;
        }

        if (action == "Register") {
            RegisterPage(request, response)(&form);
            return;
        }

        if (action != "Login") {
            lstr.error() << "Invalid action" << endl;
            IndexPage(request, response)(&form);
            return;
        }

        string username = form.get("username");
        string password = form.get("password");
        if (username != "test") {
            throw validation_error("Unknown username");
        }
        if (password != "one") {
            throw validation_error("Invalid password");
        }
        lstr << "Valid Credentials" << endl;
    } catch (...) {
        lstr.error() << "Username and password do not match" << endl;
        form.add("error", "Username and Password do not match.");
        IndexPage(request, response)(&form);
        return;
    }
    HomePage(request, response)(&form);
}
