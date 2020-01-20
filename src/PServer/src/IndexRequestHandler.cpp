//
// Created by cenicol on 7/19/19.
//

#include "IndexRequestHandler.hpp"
#include "IndexPage.hpp"

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTMLForm.h>

using Poco::Util::Application;

using namespace Poco::Net;
using namespace std;

IndexRequestHandler::IndexRequestHandler()
{
}

IndexRequestHandler::~IndexRequestHandler()
{

}

void IndexRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    Application &app = Application::instance();
    app.logger().information(__PRETTY_FUNCTION__);

    HTMLForm form(request, request.stream());

    IndexPage(request,response)(&form);
}
