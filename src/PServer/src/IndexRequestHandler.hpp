//
// Created by cenicol on 7/19/19.
//

#ifndef POCO_CHAT_INDEXREQUESTHANDLER_HPP
#define POCO_CHAT_INDEXREQUESTHANDLER_HPP

#include "Poco/Net/HTTPRequestHandler.h"

#include <PServer/PocoForwards.hpp>

/// Return a HTML document with the current date and time.
class IndexRequestHandler : public Poco::Net::HTTPRequestHandler
{
public:
    IndexRequestHandler();

    virtual ~IndexRequestHandler();

    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


#endif //POCO_CHAT_INDEXREQUESTHANDLER_HPP
