#include "Assignment.h"
#include "Course.h"
#include <iostream>

Assignment::Assignment(const std::string& desc, const std::string& dl, Course* crs)
    : description(desc), deadline(dl), course(crs) {
}

std::string Assignment::getDescription() const {
    return description;
}

std::string Assignment::getDeadline() const {
    return deadline;
}

Course* Assignment::getCourse() const {
    return course;
}

void Assignment::submit() const {
    std::cout << "Assignment submitted: " << description << "\n";
    std::cout << "Course: " << course->getCourseName() << "\n";
    std::cout << "Deadline: " << deadline << "\n";
}