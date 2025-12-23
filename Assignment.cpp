#include "Assignment.h"
#include "Course.h"
#include <iostream>

using namespace std;

Assignment::Assignment(const string& desc, const string& dl, Course* crs)
    : description(desc), deadline(dl), course(crs) {
}

string Assignment::getDescription() const {
    return description;
}

string Assignment::getDeadline() const {
    return deadline;
}

Course* Assignment::getCourse() const {
    return course;
}

void Assignment::submit() const {
    cout << "Assignment submitted: " << description << "\n";
    cout << "Course: " << course->getCourseName() << "\n";
    cout << "Deadline: " << deadline << "\n";
}