//
// Created by cenicol on 7/23/19.
//

#ifndef POCO_CHAT_HTMLPAGE_HPP
#define POCO_CHAT_HTMLPAGE_HPP

#include <PServer/PocoForwards.hpp>

class HTMLPage {
public:
    HTMLPage();

    virtual ~HTMLPage();

    virtual void write(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) = 0;
};


#endif //POCO_CHAT_HTMLPAGE_HPP
