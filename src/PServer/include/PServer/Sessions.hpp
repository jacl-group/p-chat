//
// Created by cenicol on 8/8/19.
//

#ifndef POCO_CHAT_SESSION_HPP
#define POCO_CHAT_SESSION_HPP

#include <PServer/User.hpp>

class Session {
public:
    explicit Session(const User &user);

    std::string getSessionId() const;

    static Session create(const User& user);

private:
    uint _id;

};


#endif //POCO_CHAT_SESSION_HPP
