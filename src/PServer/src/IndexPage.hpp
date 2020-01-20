//
// Created by cenicol on 7/23/19.
//

#ifndef POCO_CHAT_INDEXPAGE_HPP
#define POCO_CHAT_INDEXPAGE_HPP

#include <PServer/HTMLPage.hpp>

#include <string>

class IndexPage : public HTMLPage {
public:
    IndexPage(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);

    void write(Poco::Net::HTMLForm* pForm = nullptr) override;

private:
    static std::string style_;

};


#endif //POCO_CHAT_INDEXPAGE_HPP
