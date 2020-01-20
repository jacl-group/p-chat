//
// Created by cenicol on 7/31/19.
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

#include "ValidateRequestHandler.hpp"
#include "ValidatePage.hpp"

#include <Poco/LogStream.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

using namespace Poco::Net;
using namespace std;

void ValidateRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
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

    ValidatePage(request,response)(&form);
}
