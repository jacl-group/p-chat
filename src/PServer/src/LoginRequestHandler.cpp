//
// Created by cenicol on 7/30/19.
//
//
//    This file is part of poco-chat.
//
//    tf is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    tf is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with tf.  If not, see <https://www.gnu.org/licenses/>.
//

#include "LoginRequestHandler.hpp"
#include "IndexPage.hpp"
#include "HomePage.hpp"
#include <RegisterPage.hpp>
#include <PServer/validation_error.hpp>
#include <PServer/Users.hpp>
#include <PServer/Sessions.hpp>

#include <Poco/LogStream.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

#include <stdexcept>

using Poco::Util::Application;

using namespace Poco::Net;
using namespace std;

void LoginRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response)
{
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
    Poco::LogStream lstr(app.logger());

    HTMLForm form(request, request.stream());
#if 1
    lstr << "Form:" << endl;
    for (auto it : form) {
        lstr << "\t" << it.first << ": " << (it.second.empty() ? "empty" : it.second) << endl;
    }
#endif

    // Ensure that this request came from a form POST.
    string method = request.getMethod();
    if (method != "POST") {
        lstr << "Invalid method: " << method << endl;
        form.add("comment", "method != POST");
        IndexPage(request, response)(&form);
        return;
    }

    try {
        // You cannot get to this page except from a form with an action.
        string action{ form.get("action")};
        lstr << "action: " << (action.empty() ? "empty" : action) << endl;
        if (action.empty()) {
            throw logic_error("Action is empty.");
        }

        // Check for the Register button pressed.
        if (action == "Register") {
            RegisterPage(request, response)(&form);
            return;
        }

        // The only other valid button is Login
        if (action != "Login") {
            throw logic_error("Invalid action.");
        }

        // Login the user

        string username = form.get("username");
        string password = form.get("password");

        User user = Users::getByHandle("username");
        if( ! user.validatePassword(password) ) {
            throw logic_error("Invalid credentials");
        }

        Session session = Sessions::create(user);
        form.add("session", session.getSessionId());

        HomePage(request, response)(&form);
    } catch(const logic_error & e) {
        lstr.error() << e.what() << endl;
        form.add("comment", e.what());
        IndexPage(request, response)(&form);
    } catch (...) {
        lstr.error() << "Username and password do not match" << endl;
        form.add("error", "Username and Password do not match.");
        IndexPage(request, response)(&form);
    }
}
