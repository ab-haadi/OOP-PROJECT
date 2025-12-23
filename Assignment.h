#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>

using namespace std;

// Forward declaration
class Course;

class Assignment {
private:
    string description;
    string deadline;
    Course* course;

public:
    Assignment(const string& desc, const string& dl, Course* crs);

    string getDescription() const;
    string getDeadline() const;
    Course* getCourse() const;

    void submit() const;
};

#endif