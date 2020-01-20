//
// Created by cenicol on 7/23/19.
//

#include "include/PServer/HTMLPage.hpp"

HTMLPage::HTMLPage(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
: request_(request)
, response_(response)
{

}

HTMLPage::~HTMLPage()
{

}

