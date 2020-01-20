//
// Created by cenicol on 7/31/19.
//

#ifndef POCO_CHAT_VALIDATEREQUESTHANDLER_HPP
#define POCO_CHAT_VALIDATEREQUESTHANDLER_HPP

#include "Poco/Net/HTTPRequestHandler.h"

#include <PServer/PocoForwards.hpp>

class ValidateRequestHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};

#endif //POCO_CHAT_VALIDATEREQUESTHANDLER_HPP
