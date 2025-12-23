#include "User.h"
#include <iostream>
using namespace std;

User::User(int id, const std::string& n, const std::string& pwd)
    : userID(id), name(n), password(pwd) {
}

int User::getUserID() const {
    return userID;
}

std::string User::getName() const {
    return name;
}