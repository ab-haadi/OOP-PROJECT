#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int userID;
    std::string name;
    std::string password;

public:
    User(int id, const std::string& n, const std::string& pwd);
    virtual ~User() {}

    // Pure virtual functions
    virtual void login() = 0;
    virtual void displayMenu() = 0;

    // Getters
    int getUserID() const;
    std::string getName() const;

    // Pure virtual
    virtual std::string getUserType() const = 0;
};

#endif