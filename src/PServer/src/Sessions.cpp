//
// Created by cenicol on 8/8/19.
//

#include "include/PServer/Session.hpp"

#include <stdexcept>

using namespace std;

Session Session::create(const User &user) {
    throw logic_error("Session::create not implemented.");
    return Session(User());
}

std::string Session::getSessionId() const {
    return std::to_string(_id);
}
