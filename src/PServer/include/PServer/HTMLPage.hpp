//
// Created by cenicol on 7/23/19.
//

#ifndef POCO_CHAT_HTMLPAGE_HPP
#define POCO_CHAT_HTMLPAGE_HPP

#include <PServer/PocoForwards.hpp>

class HTMLPage {
public:
    HTMLPage(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    virtual ~HTMLPage();

    virtual void write(Poco::Net::HTMLForm* pForm= nullptr) = 0;

    void operator()(Poco::Net::HTMLForm* pForm) {
        write(pForm);
    }

protected:
    Poco::Net::HTTPServerRequest& request_;
    Poco::Net::HTTPServerResponse& response_;
};


#endif //POCO_CHAT_HTMLPAGE_HPP
