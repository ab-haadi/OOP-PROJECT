#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    int userID;
    string name;
    string password;

public:
    User(int id, string n, string pwd);
    virtual ~User() {}

    // Pure virtual functions (abstract class)
    virtual void login() = 0;
    virtual void displayMenu() = 0;

    // Getters
    int getUserID() const;
    string getName() const;
    string getUserType() const;

protected:
    virtual string getUserTypeString() const = 0;
};

#endif