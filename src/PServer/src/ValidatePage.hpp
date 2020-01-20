//
// Created by cenicol on 7/31/19.
//

#ifndef POCO_CHAT_VALIDATEPAGE_HPP
#define POCO_CHAT_VALIDATEPAGE_HPP

#include <include/PServer/HTMLPage.hpp>

class ValidatePage : public HTMLPage {
public:
    ValidatePage(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    void write(Poco::Net::HTMLForm* pForm= nullptr) override;

};


#endif //POCO_CHAT_VALIDATEPAGE_HPP
