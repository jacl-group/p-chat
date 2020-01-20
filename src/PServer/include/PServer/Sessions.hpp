//
// Created by cenicol on 8/8/19.
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

#ifndef POCO_CHAT_SESSIONS_HPP
#define POCO_CHAT_SESSIONS_HPP

#include <PServer/User.hpp>
#include <Session.hpp>

class Sessions {
public:
    explicit Sessions(const User &user);

    static Session create(const User& user);

private:
    uint _id;

};


#endif //POCO_CHAT_SESSIONS_HPP
