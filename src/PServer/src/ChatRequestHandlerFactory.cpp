//
// Created by cenicol on 6/8/19.
//
//
//    This file is part of tf.
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
#include <PServer/IndexRequestHandler.hpp>
#include <PServer/DebugRequestHandler.hpp>

//#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include "Poco/Util/ServerApplication.h"

#include <sstream>

using Poco::Util::Application;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;

using namespace Poco::Net;
using namespace std;

ChatRequestHandlerFactory::ChatRequestHandlerFactory()
{
}

HTTPRequestHandler *ChatRequestHandlerFactory::createRequestHandler(const HTTPServerRequest &request) {
    Application& app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);
    app.logger().information("Request from " + request.clientAddress().toString());
    app.logger().information("Request to " + request.serverAddress().toString());

    ostringstream osSize;
    osSize << "Size: " << request.size();

    app.logger().information(osSize.str());
    for (auto item = request.begin(); item != request.end(); ++item) {
        ostringstream oss;
        oss << "\t" << item->first << ": " << item->second;
        app.logger().information(oss.str());
    }

    if (request.getURI() == "/") {
        return new IndexRequestHandler();
    } else {
        return new DebugRequestHandler();
        return 0;
    }
}
