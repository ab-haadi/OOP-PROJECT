//user header file

#include "User.h"

User::User(int id, const std::string& n, const std::string& pwd)
    : userID(id), name(n), password(pwd) {
}

int User::getUserID() const {
    return userID;
}

std::string User::getName() const {
    return name;
}