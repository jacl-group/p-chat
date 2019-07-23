//
// Created by cenicol on 7/21/19.
//

#ifndef POCO_CHAT_DEBUGREQUESTHANDLER_HPP
#define POCO_CHAT_DEBUGREQUESTHANDLER_HPP

#include "Poco/Net/HTTPRequestHandler.h"

#include <PServer/PocoForwards.hpp>

class DebugRequestHandler  : public Poco::Net::HTTPRequestHandler {

public:
    DebugRequestHandler();


    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;


};

#endif //POCO_CHAT_DEBUGREQUESTHANDLER_HPP
