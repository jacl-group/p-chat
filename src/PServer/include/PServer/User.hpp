//
// Created by cenicol on 8/8/19.
//
//
//    This file is part of poco-chat.
//
//    tf is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    tf is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with tf.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef POCO_CHAT_USER_HPP
#define POCO_CHAT_USER_HPP

#include <string>

#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/SQLite/Connector.h>
//#include <initializer_list>

using Poco::Data::Statement;

class User {
public:
    User();
    User(const std::string& email, const std::string& handle, const std::string& password);
    User(std::initializer_list<std::string> list);

    void insert(Poco::Data::Session& session);
    bool validatePassword(const std::string& password);

    std::string email_;
    std::string handle_;
    std::string password_;
};


#endif //POCO_CHAT_USER_HPP
