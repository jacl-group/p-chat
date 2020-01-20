//
// Created by cenicol on 7/30/19.
//

#include "RegisterRequestHandler.hpp"
#include "IndexPage.hpp"
#include "HomePage.hpp"
#include <RegisterPage.hpp>
#include <ValidatePage.hpp>

#include <Poco/LogStream.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

using namespace Poco::Net;
using namespace std;

void
RegisterRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
    Poco::LogStream lstr(app.logger());

    HTMLForm form(request, request.stream());
#if 1
    lstr << "Form:" << endl;
    for (auto it : form) {
        lstr << "\t" << it.first << ": " << it.second << endl;
    }
#endif

    string method = request.getMethod();
    if (method != "POST") {
        lstr << "Invalid method: " << method << endl;
        form.add("comment", "method != POST");
        IndexPage(request, response)(&form);
        return;
    }

    try {
        // You cannot get to this page except from a form with an action.
        string action{form.get("action")};
        lstr << "action: " << (action.empty() ? "empty" : action) << endl;
        if (action.empty()) {
            throw logic_error("Action is empty.");
        }

        // Check for the Register button pressed.
        if (action == "Register") {
            return;
        }

        // The only other valid button is Login
        if (action != "Register") {
            throw logic_error("Invalid action.");
        }

        ValidatePage(request, response)(&form);
    } catch (const logic_error &e) {
        lstr.error() << e.what() << endl;
        form.add("comment", e.what());
        IndexPage(request, response)(&form);
    } catch (...) {
        RegisterPage(request, response)(&form);
    }
}