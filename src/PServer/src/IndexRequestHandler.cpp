//
// Created by cenicol on 7/19/19.
//

#include <PServer/IndexRequestHandler.hpp>
#include "include/PServer/IndexPage.hpp"


IndexRequestHandler::IndexRequestHandler()
{
}

void IndexRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
{
    IndexPage page;

    page.write(request, response);
}
