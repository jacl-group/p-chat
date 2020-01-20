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

#include "include/PServer/Users.hpp"

#include <include/PServer/HTTPChatServer.hpp>

#include <Poco/Exception.h>

#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/SQLite/Connector.h>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

void Users::createUsers()
{
    // create a session
    Session session = HTTPChatServer::getPool();

    // drop user table, if it exists
    session << "DROP TABLE IF EXISTS User", now;

    // (re)create user table
    session << "CREATE TABLE User (Email VARCHAR(60), Handle VARCHAR(30), Password VARCHAR(32))", now;

    // insert some rows
    User user {"john.c.bowers@earthlink.net", "Dark Traveler", "password"};
    user.insert(session);

#if 0
    Statement insert(session);
    insert << "INSERT INTO User VALUES(?, ?, ?)",
      use(user.email_),
      use(user.handle_),
      use(user.password_);

    insert.execute();
#endif

    user = {"cassieenicol@gmail.com", "Cassie", "password"};
    user.insert(session);

    session.close();
}

User Users::getByHandle(const std::string &handle)
{
    throw Poco::NotFoundException("Handle not found.");
    return User();
};
