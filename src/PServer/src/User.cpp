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

#include "include/PServer/User.hpp"

#include <Poco/Data/Session.h>
#include <Poco/Data/Statement.h>
#include <Poco/Data/SQLite/Connector.h>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

using namespace std;

User::User()
: email_()
, handle_()
, password_()
{}

User::User(const std::string& email, const std::string& handle, const std::string& password)
: email_(email)
, handle_(handle)
, password_(password)
{}

User::User(std::initializer_list<std::string> list)
: email_()
, handle_()
, password_()
{
    auto it = list.begin();
    email_ = *it++;
    handle_ = *it++;
    password_ = *it++;
}

bool User::validatePassword(const std::string &password)
{
    return false;
}

void User::insert(Poco::Data::Session& session) {
    cout << "insert " << email_
    << endl;
    Statement insert(session);
    insert << "INSERT INTO User VALUES(?, ?, ?)",
            use(email_),
            use(handle_),
            use(password_);
    insert.execute();
}