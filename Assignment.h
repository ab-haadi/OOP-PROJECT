#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

// Forward declaration
class Course;

class Assignment {
private:
    std::string description;
    std::string deadline;
    Course* course;

public:
    Assignment(const std::string& desc, const std::string& dl, Course* crs);

    // Getters
    std::string getDescription() const;
    std::string getDeadline() const;
    Course* getCourse() const;

    // Assignment methods
    void submit() const;
};

#endif