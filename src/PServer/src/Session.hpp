//
// Created by cenicol on 8/8/19.
//

#ifndef POCO_CHAT_SESSION_HPP
#define POCO_CHAT_SESSION_HPP

#include <string>

class Session {
public:

    std::string getSessionId() const;

private:
    uint _id;

};


#endif //POCO_CHAT_SESSION_HPP
