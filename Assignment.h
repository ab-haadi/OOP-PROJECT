#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include "Course.h"
#include <string>

class Course; // Forward declaration

class Assignment {
private:
    string description;
    string deadline;
    Course* course;

public:
    Assignment(string desc, string dl, Course* crs);

    // Getters
    string getDescription() const;
    string getDeadline() const;
    Course* getCourse() const;

    // Assignment methods
    void submit() const;
};

#endif