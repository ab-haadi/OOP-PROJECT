#include "Assignment.h"
#include <iostream>

Assignment::Assignment(string desc, string dl, Course* crs)
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