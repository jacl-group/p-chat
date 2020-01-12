//
// Created by cenicol on 8/8/19.
//

#ifndef POCO_CHAT_USERS_HPP
#define POCO_CHAT_USERS_HPP


class Users {
public:
    Users();

    User getByHandle(const std::string& handle);
};


#endif //POCO_CHAT_USERS_HPP
