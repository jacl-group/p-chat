//
// Created by cenicol on 7/30/19.
//

#ifndef POCO_CHAT_LOGINREQUESTHANDLER_HPP
#define POCO_CHAT_LOGINREQUESTHANDLER_HPP

#include <Poco/Net/HTTPRequestHandler.h>

class LoginRequestHandler : public Poco::Net::HTTPRequestHandler {
public:
    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};


#endif //POCO_CHAT_LOGINREQUESTHANDLER_HPP
