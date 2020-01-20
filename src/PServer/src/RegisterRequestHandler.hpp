//
// Created by cenicol on 7/30/19.
//

#ifndef POCO_CHAT_REGISTERREQUESTHANDLER_HPP
#define POCO_CHAT_REGISTERREQUESTHANDLER_HPP

#include <Poco/Net/HTTPRequestHandler.h>

class RegisterRequestHandler : public Poco::Net::HTTPRequestHandler {
public:

    void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};


#endif //POCO_CHAT_REGISTERREQUESTHANDLER_HPP
