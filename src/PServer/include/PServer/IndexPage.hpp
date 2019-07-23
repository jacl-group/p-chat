//
// Created by cenicol on 7/23/19.
//

#ifndef POCO_CHAT_INDEXPAGE_HPP
#define POCO_CHAT_INDEXPAGE_HPP

#include <PServer/HTMLPage.hpp>

class IndexPage : public HTMLPage {
public:
    void write(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response) override;
};


#endif //POCO_CHAT_INDEXPAGE_HPP
