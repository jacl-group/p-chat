//
// Created by cenicol on 7/30/19.
//

#ifndef POCO_CHAT_VALIDATION_ERROR_HPP
#define POCO_CHAT_VALIDATION_ERROR_HPP

#include <stdexcept>

class validation_error : public std::domain_error
{
public:
    explicit validation_error(const std::string& what_arg)
    : domain_error(what_arg)
    {

    }

    explicit validation_error(const char* what_arg)
    : domain_error(what_arg)
    {

    }

};

#endif //POCO_CHAT_VALIDATION_ERROR_HPP
