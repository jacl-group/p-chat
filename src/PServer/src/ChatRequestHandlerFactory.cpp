//
// Created by cenicol on 6/8/19.
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

#include <PServer/ChatRequestHandlerFactory.hpp>
#include "IndexRequestHandler.hpp"
#include <PServer/DebugRequestHandler.hpp>
#include "RegisterRequestHandler.hpp"
#include "LoginRequestHandler.hpp"
#include "ValidateRequestHandler.hpp"

#include <Poco/LogStream.h>
#include <Poco/Net/HTTPServerRequest.h>
#include "Poco/Util/ServerApplication.h"

#include <regex>
#include <sstream>

using Poco::LogStream;
using Poco::Util::Application;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;

using namespace Poco::Net;
using namespace std;

ChatRequestHandlerFactory::ChatRequestHandlerFactory() {
}

HTTPRequestHandler *ChatRequestHandlerFactory::createRequestHandler(const HTTPServerRequest &request) {
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
    app.logger().information("Request from " + request.clientAddress().toString());
    app.logger().information("Request to " + request.serverAddress().toString());

    LogStream lstr(app.logger());

    // Log the HTTP header records
    lstr << "Size: " << request.size() << endl;
    for (auto item = request.begin(); item != request.end(); ++item) {
        lstr << "\t" << item->first << ": " << item->second << endl;
    }

    // pattern: slash (alpha-num | dot)+
    string pattern{R"(/([[:alnum:].]+))"};
    regex e{pattern};

    // Get the Action from the URI
    string uri = request.getURI();
    smatch m;
    bool found = regex_search(uri, m, e);

    // The action is the first match. (m[0] is the entire pattern matched by e)
    string action{};
    if (found && (m.size() > 1)) {
        action = m[1].str();
    }

#if 1
    lstr << "uri: " << uri << endl;
    lstr << "action: " << (action.empty() ? "empty" : action) << endl;
#endif

    if (action.empty()) {
        return new IndexRequestHandler();
    } else if( action == "signin" ) {
        return new LoginRequestHandler();
    } else if (action == "register") {
        return new RegisterRequestHandler();
    } else if (action == "validate") {
        return new ValidateRequestHandler();
    } else {
        return new DebugRequestHandler();
    }
}
