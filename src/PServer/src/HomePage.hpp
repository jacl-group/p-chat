//
// Created by cenicol on 7/30/19.
//

#ifndef POCO_CHAT_HOMEPAGE_HPP
#define POCO_CHAT_HOMEPAGE_HPP

#include <include/PServer/HTMLPage.hpp>

class HomePage : public HTMLPage {
public:
    HomePage(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    void write(Poco::Net::HTMLForm* pForm= nullptr) override;

};


#endif //POCO_CHAT_HOMEPAGE_HPP
